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



SIGAI历史文章汇总：https://mp.weixin.qq.com/s/UNxsQnT5N_d1xFN31_7AKA

[Kaggle实战](https://www.bilibili.com/video/av26286657?from=search&seid=3969064430081332942)

kaggle （凯歌哦）

Kaggle实战视频相关代码与课件：链接：https://pan.baidu.com/s/1dRGcmjMsVYyC-MnXFsJqPA 密码：49xy

**获取最新的中文版小抄表资料包**链接**:** https://pan.baidu.com/s/1slYqSOH 密码: ueht



面试中的算法和准备过程（算法原理与实现）https://www.bilibili.com/video/av24174209/?p=19



项目描述：

- 猫狗大战（猫狗分类）

  kaggle 上的一个竞赛。目标是使用深度学习方法识别图片是猫还是狗。数据来自kaggle，数据分为训练集和测试集，训练集包含了25000张猫狗的图片，测试集包含了12500张猫狗的图片。

  **评价指标**：使用对数损失（Log loss）也叫交叉熵；采用交叉熵作为损失函数可以有效的解决梯度消失和梯度爆炸的问题。

  **数据预处理**：通过对图片中的色彩-像素进行IQR分析，发现有些无关的图片和地分别率的图片，使用IQR分析异常图片的效果不是太好，经过尝试后最后选择 InceptionV3  Top-10将训练结果和ImageNet构建的猫狗集合对比，排查训练集中的异常图片。处理完异常图片后将训练集中猫狗图片分别放在不同的文件夹区分，为 Keras 的 ImageDataGenerator 使用。

  **模型搭建**：使用 keras 框架实现迁移学习部分。选择 ResNet50、Xception、Inception V3（综合考虑模型的分类准确率和大小）三个模型导入到 keras 进行训练生成迁移学习特征向量（导入过程要对三个模型的输入图片做resize 224、299）。

  - ResNet：ResNet 引入了残差网络结构，通过这种残差网络结构，可以把网络层弄的很深，并且最终的分类效果也非常好（残差项原本是带权值的，但 ResNet 用恒等映射代替之 --- 将ReLU激活函数变成y=x的线性函数）

  - Inception V3：一个重要的改进是把较大的二维卷积拆成了两个较小的一维卷积，加速运算，减少过拟合，同时还更改了Inception Module的结构

  - Xception：实际上采用了类似于 ResNet 的网络结构，主体部分采用了模块化设计。Xception 是 google 继 Inception 后提出的对 Inception v3 的另一种改进，主要是采用 depthwise separable convolution（深度可分的卷积） 来替换原来Inception v3中的卷积操作。（两个卷积层之间是否有激活函数。 原来的 Inception 中间是有 ReLU 激活的。 但实验结果证明Xception不加激活效果更好。）

  **模型训练&模型调参**：载入这些特征向量，并且将它们合成一条特征向量（每个模型都将图片处理成`1*2048`的行向量，将这三个行向量拼接得到一个`1*6144`的行向量作为数据预处理的结果）。需要注意的是要用shuffle把数据打乱。载入预处理的数据之后，先进行一次概率为 0.5 的 dropout，然后直接连接输出层，激活函数为 Sigmoid，优化器为 Adadelta，输出一个零维张量，表示某张图片中有狗的概率。

  **模型评估**：可视化准确率曲线，损失函数曲线观察到的结果是准去率和loss在训练集和验证集上都很很好的表现。将测试集的处理结果提交到kaggle上，loss为0.04150，和验证集的loss近似。

  **项目部署**：项目使用 Keras 和 Flask 搭建部署一个简单易用的深度学习图像网页应用，可以通过网页导入一张彩色猫或者狗的图片预测是猫或者狗的概率。webapp用daocker打包成了镜像文件，可以快速部署并复现实验结果。

  **合理性分析**：Xception，InceptionV3 和 ResNet50 这三个模型进行组合迁移学习，效果比先单个神经网络模型效果好。这里利用了 bagging 的思想，通过多个模型处理数据并进行组合，可以有效降低模型的方差，减少过拟合程度，提高分类准确率。

  **项目思考**：项目使用的 Xception，InceptionV3 和 ResNet50 这三个模型进行了提取特征向量，然后将特征向量直接拼接，忽略了特征之间的位置关系。除了这三个模型，还可以增加更多新的模型，或者使用stacking的方法进行模型融合，进一步降低方差，提高分类的准确率。还可以从原始样本上入手，有些图片的分类概率正确，但是不够确定，可以先做一部分处理，然后让模型更加确定。

  **需要作出的改进**：

  相比 Keras，TensorFlow 真的真的太麻烦了，但是 Google 为什么要把 TensorFlow 做的这么麻烦呢？个人认为是为了运行的高效率和极大的灵活性做出了让步。TensorFlow 是经过工业界实际产品考验过的框架，生态及其丰富，想实现一个功能，有多种写法，学起来有一种 C++ 的感觉，Keras 更像是为了快速出活的框架，如果想做一些改动十分的麻烦，Keras 的默认 backend 就是 TensorFlow，所以 Keras 的执行效率是比 TensorFlow 慢很多的。TensorFlow1.4 里面已经把 `tf.contrib.keras` 更改为核心模块 `tf.keras`，所以 TensorFlow 以后用起来应该也会方便很多。最后还想说的是 PyTorch，好多人都推荐，说不仅仅有 TensorFlow 的高效率，而且很 pythonic，可以在任意层和 numpy 数组进行转化。

- 电影推荐系统：



```C++
/*
* 需要注意的问题：
* 1. 内存重叠的处理
* 2. 临时变量太多或者没有安全释放
* 3. 没有测试内存越界
* 4. 指针操作不熟悉
*/
void *memmove(vild *dest, const void *src, size_t n)
{
	char *p1 = dest;
    const char *p2 = src;
    
    if(p2 < p1){
        p2 += n;
        p1 += n;
        while(n-- != 0)
            *--p1 = *--p2;
    } else{
        while(n-- != 0)
            *p1++ = *p2++;
    }

    return p1;
}
```











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