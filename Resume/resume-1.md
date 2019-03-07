> [程序员这样优化简历，一投制胜](https://blog.csdn.net/ouyang_peng/article/details/50747145)
>
> [软件工程师简历模板（突出专业技能）](https://cv.qiaobutang.com/lp/51bed69e0cf27180ee1f95d6)



面试题：

> [总结：常见算法工程师面试题目整理(一)](https://www.jianshu.com/p/c3c921dca07b)
>
> [总结：常见算法工程师面试题目整理(二)](https://www.jianshu.com/p/4f91f0dcba95)
>
> [算法工程师面试总结](https://zhuanlan.zhihu.com/p/28760907)
>
> [如何准备机器学习工程师的面试 ？](https://zhuanlan.zhihu.com/p/29969587)
>
> [机器学习/算法19家公司面试总结（内含薪资）](https://www.jianshu.com/p/fc9b6e1b4041)
>
> []()

## 保险赔偿预测

数据集来源：好事达Allstate保险公司数据集
数据集维度：188k x 132
数据分析：

- 大概有116个种类属性（如它们的名字所示）和14个连续（数字）属性。 此外，还有ID和赔偿。总计为132列。
- 缺失值（无）
- 大部分的分类特征（72/116）是二值的，绝大多数特征（88/116）有四个值，其中有一个具有326个值的特征（一天的数量？）。
- 赔偿值有偏度，数据倾斜，对数据进行对数变换通常可以改善倾斜，可以使用 `np.log`
- 特征之间的相关性，几个特征之间有很高的相关性

数据处理：

- 赔偿值loss做对数转换
- 使用标签编码器分类特征
- 数据分成连续和离散特征（分类数据类型转换成category，好处是**除了占用内存节省外，另一个额外的好处是计算效率有了很大的提升**）

构建模型：

- 首先，我们训练一个基本的xgboost模型，然后进行参数调节通过交叉验证来观察结果的变换，使用平均绝对误差来衡量 mean_absolute_error(np.exp(y), np.exp(yhat))。

  xgboost 自定义了一个数据矩阵类 DMatrix，会在训练开始时进行一遍预处理，从而提高之后每次迭代的效率

- 参数

  - 'booster':'gbtree',
  - 'objective': 'multi:softmax', 多分类的问题
  - 'num_class':10, 类别数，与 multisoftmax 并用
  - 'gamma':损失下降多少才进行分裂
  - 'max_depth':12, 构建树的深度，越大越容易过拟合
  - 'lambda':2, 控制模型复杂度的权重值的L2正则化项参数，参数越大，模型越不容易过拟合。
  - 'subsample':0.7, 随机采样训练样本
  - 'colsample_bytree':0.7, 生成树时进行的列采样
  - 'min_child_weight':3, 孩子节点中最小的样本权重和。如果一个叶子节点的样本权重和小于min_child_weight则拆分过程结束
  - 'silent':0 ,设置成1则没有运行信息输出，最好是设置为0.
  - 'eta': 0.007, 如同学习率
  - 'seed':1000,
  - 'nthread':7, cpu 线程数

- 使用交叉验证 `xgb.cv`

- XGBoost 参数调节

  - Step 1: 选择一组初始参数

  - Step 2: 改变 `max_depth` 和 `min_child_weight`.

  - Step 3: 调节 `gamma` 降低模型过拟合风险.

  - Step 4: 调节 `subsample` 和 `colsample_bytree` 改变数据采样策略.

  - Step 5: 调节学习率 `eta`.  减小学习率并增大树个数











