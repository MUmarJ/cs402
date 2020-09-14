setwd("C:/Users/MUmarJ/Classes/CS402/HW1")
getwd()
data1 <- read.csv("spice.din", sep=" ",header=F, stringsAsFactors = F)
head(data1)
str(data1)
require(lattice)
require(psych)
addressFreq <- table(data1$v2)
addressFreq
summary(data1)
addressFreq <- table(data1[,2])
describe(data1)
summary(addressFreq)
barplot(addressFreq, main="Frequency of address operations")


x1<-data1$V1
maxX1<-max(table(x1))
bp<-barplot(table(data1$V1), xaxt="n", main="Frequency of operations",ylim=(c(0,maxX1)))
axis(1, at=1:3, labels=c("Read","Write","Fetch"))
options(scipen = 5)
text(x=bp, y= table(x)/2, labels=as.character(table(x)))

freqOperations<-table(data1[,1])
max(freqOperations)
