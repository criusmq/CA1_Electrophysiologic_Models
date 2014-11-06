library(ggplot2)
DF <- read.table("/Users/maoss2/NEURON/CA1_cell_test/Stimulation_case_per_case/CA1_Electrophysiologic_Models/CA1_Electrophysiologic_Models/Model_Harvey&Svoboda_Stim/spine1_1plot_cai.dat")
print( nrow(DF))
#DF <- DF[79000:nrow(DF),]
#print( nrow(DF))
colnames(DF) = c('x', 'y')
theme_set(theme_bw())
ggplot(DF,aes(x,y))+geom_point()+
    geom_smooth()
#ggsave("fig.png")

# dev.new()

# ggplot(DF,aes(x,y))+geom_point()+
    # geom_smooth()
