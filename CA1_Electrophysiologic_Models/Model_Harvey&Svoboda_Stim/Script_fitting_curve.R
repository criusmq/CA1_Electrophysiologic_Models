library(ggplot2)
DF <- read.table("/Users/maoss2/NEURON/CA1_cell_test/Stimulation_case_per_case/VirtualCell_Models/RasGTP_model1D_data.dat")
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
