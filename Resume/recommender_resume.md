## 项目描述 -- 电影推荐系统

**项目概括**：

**数学抽象**：

**数据预处理**：

**评价指标**：

**模型搭建**：

**模型训练&模型调参**：

**模型评估**：

**项目部署**：

**合理性分析**：

**项目思考**：









电影推荐系统：使用开源MovieLens数据集，基于TensorFlow使用文本卷积网络生成movie特征矩阵和user特征矩阵，在推荐同类型电影根据当前看的电影特征向量与整个电影特征矩阵的余弦相似度，取相似度最大的Top N个。训练完成后的模型预测 MSE loss 为0.8。 



本项目使用的是[MovieLens 1M 数据集](https://grouplens.org/datasets/movielens/)，这些数据集包含6040个用户在3883部电影上的100,0209个匿名评级。

数据集分为三个文件：用户数据 users.dat，电影数据 movies.dat 和评分数据 ratings.dat。



除了标准的电影推荐算法，我还用了深度学习来处理海报，并将相似的电影推荐给用户。最终目标是模仿人类视觉，并仅仅通过观察海报，就能用深度学习创建一个直观的电影推荐系统。





**协同过滤**

粗略地说，有三种类型的推荐系统（不包括简单的评级方法）

- 基于内容的推荐
- 协同过滤
- 混合模型

“基于内容的推荐”是一个回归问题，我们把电影内容作为特征，对用户对电影的评分做预测。

而在“协同过滤”推荐系统中，一般无法提前获得内容特征。是通过用户之间的相似度（用户们给了用一个电影相同的评级）和电影之间的相似度（有相似用户评级的电影），来学习潜在特征，同时预测用户对电影的评分。此外，学习了电影的特征之后，我们便可以衡量电影之间的相似度，并根据用户历史观影信息，向他/她推荐最相似的电影。

“基于内容的推荐”和“协同过滤”是10多年前最先进的技术。很显然，现在有很多模型和算法可以提高预测效果。比如，针对事先缺乏用户电影评分信息的情况，可以使用隐式矩阵分解，用偏好和置信度取代用户电影打分——比如用户对电影推荐有多少次点击，以此进行协同过滤。另外，我们还可以将“内容推荐”与“协同过滤”的方法结合起来，将内容作为侧面信息来提高预测精度。这种混合方法，可以用“学习进行排序”（"Learning to Rank" ）算法来实现。

该项目中，我会聚焦于“协同过滤”方法。首先，我将讨论如何**不使用回归**，**而是电影（用户）相似度来预测评分**，并基于相似度做电影推荐。然后，我将讨论如何**使用回归同时学习潜在特征、做电影推荐**。最后会谈谈 如何在推荐系统中使用深度学习。





## Reference

> [如何用深度学习推荐电影？教你做自己的推荐系统！](https://www.leiphone.com/news/201705/rOD6wP779DLXx8mI.html) - 雷锋网（不错的文章）
>
> [TensorFlow实战——个性化推荐](https://blog.csdn.net/chengcheng1394/article/details/78820529) - CSDN（本项目的参考）
>
> [基于 Spark 和 Flask 的一个可伸缩的电影推荐系统](http://python.jobbole.com/82207/) - 伯乐在线
>
> [电影推荐系统构建](http://blog.lkj666.top/2018/01/11/%E7%94%B5%E5%BD%B1%E6%8E%A8%E8%8D%90%E7%B3%BB%E7%BB%9F%E6%9E%84%E5%BB%BA/) - （不错的实现有github）
>
> [在Python中实现你自己的推荐系统](http://python.jobbole.com/85516/) -- （面试大纲）
>
> [数据分析/人工智能经典案例04 - 基于SVD协同过滤算法实现的电影推荐系统](https://www.zybuluo.com/rianusr/note/1195225) - （三大方法实现推荐）
>
> [深度学习在推荐系统上的应用](https://zhuanlan.zhihu.com/p/33214451)
>
> [基于MovieLens-1M数据集实现的协同过滤算法demo](https://github.com/Lockvictor/MovieLens-RecSys)
>
>
>
> > ### GitHub
> >
> > [一个网站，一个推荐系统](https://github.com/TomatoFish666/RecSystem) -- （Django）
> >
> > [一个电影推荐系统，毕业设计](https://github.com/JaniceWuo/MovieRecommend) -- （Django）
> >
> > [推荐系统，web端展示基于django](https://github.com/charlesXu86/Rnews-Recommendation) -- （Django）
> >
> > [利用MovieLens数据，Pearson相似度，分别基于User和Item构建一个简单的kNN推荐系统，并给出RMSE评测](https://github.com/fuhailin/Recommender-System)
> >
> > [推荐系统实例](https://github.com/lpty/recommendation)
> >
> > [MapReduce实现基于物品的协同过滤算法，即电影推荐系统](https://github.com/ParadeTo/Recommend)
> >
> > [推荐系统实践(基于近邻和LFM的推荐系统)](https://github.com/1092798448/RecSys)
> >
> > [卷积神经网络（CNN）构建推荐系统](https://github.com/moneyDboat/ConvMF)
> >
> > ### 推荐系统资源汇总
> >
> > [推荐系统学习资料、源码、及读书笔记](https://github.com/singmiya/recsys)
> >
> > [Recommender-System论文、学习资料以及业界分享](https://github.com/zhaozhiyong19890102/Recommender-System/blob/7e09f8a1ed63660239296806f0c0bb5e1d5711c5/README.md)
> >
> > [tensorflow实战练习，包括强化学习、推荐系统、nlp等](https://github.com/princewen/tensorflow_practice) - （Blog 汇总）
> >
> > [大数据/数据挖掘/推荐系统/机器学习相关资源](https://github.com/weiweifan/Big-Data-Resources)
> >
> > [推荐系统资料笔记收录/ Everything about Recommendation System. 专题/书籍/论文/产品](https://github.com/fire717/Recommendation-system)
> >
> > ### Java 实现的推荐系统
> >
> > [基于Spark的电影推荐系统，包含爬虫项目、web网站、后台管理系统以及spark推荐系统](https://github.com/ZzXxL1994/Movie_Recommend)
> >
> > [电影推荐系统、电影推荐引擎、使用Spark完成的电影推荐引擎](https://github.com/wangj1106/recommendMoteur) - （GitHub java实现）
> >
> > [基于Apache Spark的Netflix电影的离线与实时推荐系统](https://github.com/LeechanX/Netflix-Recommender-with-Spark)
> >
> > [将SVD应用于推荐系统中的评分预测问题](https://github.com/jingchenUSTC/SVDRecommenderSystem)
> >
> > [基于spark、mahout和spring boot构建的推荐系统](https://github.com/javachen/grab)
> >
> > [影视推荐系统网站部分](https://github.com/FourSpaces/RecommendationMovie)
>
> > [基于用户的协同过滤算法的电影推荐系统](https://blog.csdn.net/u012050154/article/details/52268057) - CSDN
> >
> > [分析9000部电影|一个简单的电影推荐系统](https://www.jianshu.com/p/4919a54fd70d) - 简书（主要体现的是数据合并与分析）
> >
> > [融合 MF 和 RNN 的电影推荐系统](https://www.jiqizhixin.com/articles/2017-12-28-20) - 机器之心（看不太懂的模型框架）