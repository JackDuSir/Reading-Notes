1. kaggle猫狗大战项目：使用Keras将Xception， InceptionV3和ResNet50 这三个模型进行迁移学习，在验证集上的准确率可以达到99.4%， 在kaggle提交的结果为0.04150，识别准确率进入 Kaggle Top 2%。项目同时基于训练好的模型使用 Flask 搭建部署了一个简单易用的猫狗识别网页应用。 webapp用daocker打包成了镜像文件，可以快速部署并复现实验结果。
2. 电影推荐系统：使用开源MovieLens数据集，基于TensorFlow使用文本卷积网络生成movie特征矩阵和user特征矩阵，在推荐同类型电影根据当前看的电影特征向量与整个电影特征矩阵的余弦相似度，取相似度最大的Top N个。训练完成后的模型预测 MSE loss 为0.8。 

3. 波士顿房价预测：使用Pandas 和Numpy 先从宏观了解数据的特征。使用sklearn对数据进行分割与重排，模型实现使用的是sklearn的[GridSearchCV](http://scikit-learn.org/stable/modules/generated/sklearn.model_selection.GridSearchCV.html)算法，回归器选择DecisionTreeRegressor。项目使用R^2（决定系数）作为回归模型的衡量标准。模型fit数据，得到最优模型。最后应用模型进行预测。最后评估模型是否对现实有指导意义。

4. 为*CharityML*寻找捐献者：这个项目设计成帮助你熟悉在sklearn中能够使用的多个监督学习算法，并提供一个评价模型在某种类型的数据上表现的方法。在机器学习中准确理解在什么时候什么地方应该选择什么算法和不应该选择什么算法是十分重要的。

   完成这个项目你将学会以下内容：

   - 知道什么时候应该使用预处理以及如何做预处理。
   - 如何为问题设置一个基准。
   - 判断在一个特定的数据集上几个监督学习算法的表现如何。
   - 调查候选的解决方案模型是否足够解决问题。

5. 创建用户分类：

6. 自动走迷宫机器人：实现一个 Q Learning 机器人。在强化学习中有五个核心组成部分，它们分别是：**环境（Environment）**、**智能体（Agent）**、**状态（State）**、**动作（Action）**和**奖励（Reward）**。在某一时间节点 $t$：
   ​    

   - 智能体在从环境中感知其所处的状态 $s_t$
   - 智能体根据某些准则选择动作 $a_t$
   - 环境根据智能体选择的动作，向智能体反馈奖励 $r_{t+1}​$

   通过合理的学习算法，智能体将在这样的问题设置下，成功学到一个在状态 $s_t$ 选择动作 $a_t$ 的策略 $\pi (s_t) = a_t$。

   在我们的项目中，我们要实现基于 Q-Learning 的强化学习算法。Q-Learning 是一个值迭代（Value Iteration）算法。与策略迭代（Policy Iteration）算法不同，值迭代算法会计算每个”状态“或是”状态-动作“的值（Value）或是效用（Utility），然后在执行动作的时候，会设法最大化这个值。因此，对每个状态值的准确估计，是我们值迭代算法的核心。通常我们会考虑**最大化动作的长期奖励**，即不仅考虑当前动作带来的奖励，还会考虑动作长远的奖励。

   在 Q-Learning 算法中，我们把这个长期奖励记为 Q 值，我们会考虑每个 ”状态-动作“ 的 Q 值，具体而言，它的计算公式为：

   $$
   q(s_{t},a) = R_{t+1} + \gamma \times\max_a q(a,s_{t+1})
   $$

   也就是对于当前的“状态-动作” $(s_{t},a)$，我们考虑执行动作 $a$ 后环境给我们的奖励 $R_{t+1}$，以及执行动作 $a$ 到达 $s_{t+1}$后，执行任意动作能够获得的最大的Q值 $\max_a q(a,s_{t+1})$，$\gamma$ 为折扣因子。

   不过一般地，我们使用更为保守地更新 Q 表的方法，即引入松弛变量 $alpha$，按如下的公式进行更新，使得 Q 表的迭代变化更为平缓。

   $$
   q(s_{t},a) = (1-\alpha) \times q(s_{t},a) + \alpha \times(R_{t+1} + \gamma \times\max_a q(a,s_{t+1}))
   $$




7. 实现一个狗品种识别算法App：



[Kaggle实战](https://www.bilibili.com/video/av26286657?from=search&seid=3969064430081332942)

kaggle （凯歌哦）

Kaggle实战视频相关代码与课件：链接：https://pan.baidu.com/s/1dRGcmjMsVYyC-MnXFsJqPA 密码：49xy



项目描述：

- 猫狗大战（猫狗分类）

  kaggle 上的一个竞赛。目标是使用深度学习方法识别图片是猫还是狗。数据来自kaggle，数据分为训练集和测试集，训练集包含了25000张猫狗的图片，测试集包含了12500张猫狗的图片。

  数据预处理：通过对图片中的色彩-像素进行IQR分析，发现有些无关的图片和地分别率的图片，使用IQR分析异常图片的效果不是太好，经过尝试后最后选择 InceptionV3 模型排查训练集中的异常图片。处理完异常图片后将训练集中猫狗图片分别放在不同的文件夹区分，为 Keras 的 ImageDataGenerator 使用。

  模型搭建：使用 keras 框架对 ResNet50、Xception、Inception V3三个模型进行训练生成迁移学习特征向量并保存。





> [常用机器学习算法总结](https://blog.csdn.net/u012050154/article/details/55106731)
>
> [8 种常见机器学习算法比较](https://juejin.im/entry/58f482470ce463006bbaff8d)
>
> [深度学习常见算法的介绍和比较](https://blog.csdn.net/abc200941410128/article/details/79269386)
>
> [[总结型***\]](http://www.aboutyun.com/forum.php?mod=forumdisplay&fid=199&filter=typeid&typeid=1020) [常用机器学习和深度学习算法总结***](http://www.aboutyun.com/thread-24907-1-1.html)
>
> [机器学习算法地图](https://bbs.pku.edu.cn/v2/post-read.php?bid=322&threadid=16495870&from_mobile_long=1)
>
> [机器学习算法地图-微信](https://mp.weixin.qq.com/s?__biz=MzU4MjQ3MDkwNA==&mid=2247485306&idx=1&sn=fc8cc8de313bdb61dcd39c1dedb240a4&chksm=fdb69aedcac113fb4b18c74248a313536ded50bade0e66b26f332ab247b148519da71ff2a3c0#rd)
>
> [用一句话总结常用的机器学习算法](https://zhuanlan.zhihu.com/p/38067616)
>
> [机器学习常用算法总结](https://blog.csdn.net/JIEJINQUANIL/article/details/52270178)
>
> [推荐系统主要算法总结及Youtube深度学习推荐算法实例概括](https://www.jiqizhixin.com/articles/2017-07-09-5)
>
> [推荐算法--总结](https://blog.csdn.net/yimingsilence/article/details/54959008)
>
> [推荐系统算法总结](https://blog.csdn.net/nanjingdreamfly/article/details/68926806)
>
> [推荐系统常用的推荐算法](https://zhuanlan.zhihu.com/p/23036112)

决策树

随机森林

逻辑斯蒂回归

SVM

朴素贝叶斯

K最近邻

K均值

Adaboost

神经网络

马尔科夫

GDBT

EM

Boosting

Bagging

PCA

LDA

---

DBN（Deep belief network） 深度信念网络

CNN（Convolution Neural Networks）卷积神经网络

RNN（Recurrent neural network） 递归神经网络













数据清洗：

算法：LR、FTRL、SVM、GBDT、XGBoost、