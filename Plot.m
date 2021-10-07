clear all;
close all;
clc;
%{
%%100
%Key comparisons
a1 = [606 549 366; 573 612 382; 508 587 375; 737 740 522; 655 598 466]
%Rotations
b1 = [184 53; 147 51; 147 46; 185 69; 165 55]
%Height
c1 = [9 10 5; 10 11 5; 7 8 6; 12 12 6; 12 9 6]
%Avg Height
d1 = [5.3 4.75 3.6; 4.84783 5.23913 3.78261; 4.34043 4.80851 3.85106; 5.93056 5.98611 4.40278; 5.93651 5.04762 4.2381]
%Avg Depth
e1 = [3.1 3.1 2.125; 3.63043 3.45652 2.13043; 2.65957 2.80851 2.14894; 3.25 3.34722 2.18056; 3.50794 2.96825 2.22222]

%%1000
%Key comparisons
a2 = [10458 9033 5401; 9915 9424 5861; 9915 10170 6578; 10626 9899 6843; 11285 11178 7416]
%Rotations
b2 = [1506 526; 1545 530; 1723 559; 1727 613; 1804 568]
%Height
c2 = [23 14 9; 18 16 9; 19 17 10; 21 22 10; 17 19 10]
%Avg Height
d2 = [11.7494 8.39206 6.85608; 9.22436 8.75427 7.08974; 9.6535 9.36625 7.33573; 10.2842 9.36815 7.44007; 9.44179 10.4239 7.5806]
%Avg Depth
e2 =[3.65261 3.08685 2.28288; 3.43162 3.24145 2.30342; 3.47935 3.24057 2.28187; 3.54795 3.40411 2.30993; 3.39403 3.23582 2.27612]

%%10000
%Key comparisons
a3 =[133324 130491 71593; 142779 129090 78151; 140892 138227 84832; 151098 147457 91061; 148606 143865 99157]
%Rotations
b3 = [15462 4522; 15907 4681; 16190 5101; 17333 5255; 17307 5396]
%Height
c3 = [22 23 13; 28 22 13; 27 25 14; 28 26 14; 29 26 14]
%Avg Height
d3 = [12.3721 12.5775 10.0776; 13.8524 12.478 10.2901; 13.7483 13.326 10.4952; 14.6797 14.1738 10.5853; 14.5832 13.7354 10.784]
%Avg Depth
e3 = [3.43793 3.26892 2.30443; 3.45286 3.27357 2.30987; 3.46731 3.34469 2.31597; 3.43166 3.33598 2.31722; 3.46349 3.38247 2.31793]

%%100000
%Key comparisons
a4 = [1703821 1679648 844391; 1692718 1631647 914073; 1724066 1661079 995145; 1781129 1679357 1063352; 1791270 1665908 1136564]
%Rotations
b4 = [124223 34102; 122548 33942; 119059 33236; 114960 32304; 108975 31235]
%Height
c4 = [35 32 16; 28 28 16; 33 32 16; 33 29 16; 32 32 16]
%Avg Height
d4 = [16.6369 16.1062 12.3142; 15.6488 15.5437 12.451; 16.4262 15.7962 12.612; 17.7552 16.0071 12.7264; 17.135 15.9307 12.8456]
%Avg Depth
e4 = [3.46931 3.21385 2.32077; 3.44623 3.19861 2.3152; 3.47255 3.23225 2.31319; 3.45454 3.25986 2.32131; 3.44282 3.28711 2.31993]

%%1000000
%Key comparisons
a5 = [18176592 17322428 8653304; 18356694 16734992 9389915; 18855843 16992324 10138158; 18792414 18276902 10793178; 18698710 18151598 11510611]
%Rotations
b5 = [815052 173150; 794487 167427; 748673 158327; 688647 145863; 621724 131141]
%Height
c5 = [34 28 16; 33 27 17; 39 31 17; 32 31 16; 36 30 16]
%Avg Height
d5 = [17.283 15.9601 12.7566; 16.8961 15.3964 12.8552; 18.6873 15.7104 12.9576; 18.3894 17.0332 12.9403; 18.0611 16.9387 13.013]
%Avg Depth
e5 = [3.44079 3.16397 2.32425; 3.46897 3.16753 2.31867; 3.46244 3.15506 2.31337; 3.44969 3.16444 2.31532; 3.41994 3.16449 2.31546]

%% key comparisons
figure; %line plot
bar(a1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Key Comparisons for 100 operations');
xlabel('Ratio');
ylabel('Key Comparisons');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(a2);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Key Comparisons for 1000 operations');
xlabel('Ratio');
ylabel('Key Comparisons');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(a3);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Key Comparisons for 10000 operations');
xlabel('Ratio');
ylabel('Key Comparisons');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(a4);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Key Comparisons for 100000 operations');
xlabel('Ratio');
ylabel('Key Comparisons');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(a5);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Key Comparisons for 1000000 operations');
xlabel('Ratio');
ylabel('Key Comparisons');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');


%% rotations

figure; %line plot
bar(b1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Rotations for 100 operations');
xlabel('Ratio');
ylabel('Rotations');
legend('Treap','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(b2);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Rotations for 1000 operations');
xlabel('Ratio');
ylabel('Rotations');
legend('Treap','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(b3);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Rotations for 10000 operations');
xlabel('Ratio');
ylabel('Rotations');
legend('Treap','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(b4);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Rotations for 100000 operations');
xlabel('Ratio');
ylabel('Rotations');
legend('Treap','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(b5);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Rotations for 1000000 operations');
xlabel('Ratio');
ylabel('Rotations');
legend('Treap','AVL Tree','Location','northeastoutside');



%% Height


figure; %line plot
bar(c1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Height of Tree for 100 operations');
xlabel('Ratio');
ylabel('Height of Tree');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(c2);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Height of Tree for 1000 operations');
xlabel('Ratio');
ylabel('Height of Tree');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(c3);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Height of Tree for 10000 operations');
xlabel('Ratio');
ylabel('Height of Tree');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(c4);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Height of Tree for 100000 operations');
xlabel('Ratio');
ylabel('Height of Tree');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(c5);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Height of Tree for 1000000 operations');
xlabel('Ratio');
ylabel('Height of Tree');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');



%% Average Height


figure; %line plot
bar(d1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Root for 100 operations');
xlabel('Ratio');
ylabel('Average Height from Root');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(d2);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Root for 1000 operations');
xlabel('Ratio');
ylabel('Average Height from Root');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(d3);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Root for 10000 operations');
xlabel('Ratio');
ylabel('Average Height from Root');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(d4);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Root for 100000 operations');
xlabel('Ratio');
ylabel('Average Height from Root');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(d5);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Root for 1000000 operations');
xlabel('Ratio');
ylabel('Average Height from Root');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');




%% Average depth


figure; %line plot
bar(e1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Bottom for 100 operations');
xlabel('Ratio');
ylabel('Average Height from Bottom');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(e2);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Bottom for 1000 operations');
xlabel('Ratio');
ylabel('Average Height from Bottom');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(e3);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Bottom for 10000 operations');
xlabel('Ratio');
ylabel('Average Height from Bottom');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(e4);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Bottom for 100000 operations');
xlabel('Ratio');
ylabel('Average Height from Bottom');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');

figure; %line plot
bar(e5);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Bottom for 1000000 operations');
xlabel('Ratio');
ylabel('Average Height from Bottom');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');
%}
%{
x = [3677 3526 3478 3610 3446 3480 3633 3479 3583 3527 ;3559 3575 3548 3513 3463 3479 3548 3528 3532 3589 ;4086 4061 4138 4084 4019 4105 4105 4128 4072 4057 ;4097 4098 4164 3954 4057 4130 4184 4127 3994 4024 ;4687 4663 4625 4696 4592 4706 4665 4759 4591 4697 ;4637 4597 4614 4690 4745 4639 4568 4697 4591 4690 ;5254 5216 5270 5160 5318 5248 5173 5290 5217 5290 ;5222 5242 5284 5279 5337 5279 5213 5164 5337 5173 ;5846 5830 5883 5840 5939 5791 5888 5933 5917 5839;5933 5881 5947 5886 5869 5821 5918 5862 5912 5813 ;]

figure; %line plot
bar(x);
xticklabels({'60:40(10000)','60:40(2K+5K+3K)','65:35(10000)','65:35(2K+5K+3K)','70:30(10000)','70:30(2K+5K+3K)','75:25(10000)','75:25(2K+5K+3K)','80:20(10000)','80:20(2K+5K+3K)'});
title('Experiments vs Node count');
xlabel('Ratio wise 10 experiments');
ylabel('Total number of nodes in final tree');
%}

%Key comparisons
a1 = [ 30187 6179370 41599; 37507 8542911 49670; 41302 10249128 55186; 46800 13794378 65336; 51094 16834503 73036]
%Rotations
b1 = [3502 3503; 4122 4120; 4516 4514; 5247 5239; 5796 5789]
%Height
c1 = [23 3514 11; 27 4132 12; 28 4526 12; 29 5251 12; 29 5801 12]
%Avg Height
d1 = [12.7863 1757 9.83841; 13.6538 2066 10.0213; 13.8893 2263 10.1935; 14.3641 2625.5 10.4429; 14.4164 2900.5 10.5905]
%Avg Depth
e1 = [3.5303 1758 1.99744; 3.52456 2067 1.99093; 3.52618 2264 1.99823; 3.51295 2626.5 1.99924; 3.50121 2901.5 1.99879]


figure; %line plot
b = bar(a1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Key Comparisons for 10000 operations');
xlabel('Ratio');
ylabel('Key Comparisons');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');
xtips1 = b(1).XEndPoints;
ytips1 = b(1).YEndPoints;
labels1 = string(b(1).YData);
text(xtips1,ytips1,labels1,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips2 = b(2).XEndPoints;
ytips2 = b(2).YEndPoints;
labels2 = string(b(2).YData);
text(xtips2,ytips2,labels2,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips3 = b(3).XEndPoints;
ytips3 = b(3).YEndPoints;
labels3 = string(b(3).YData);
text(xtips3,ytips3,labels3,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')


figure; %line plot
b = bar(b1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Rotations for 10000 operations');
xlabel('Ratio');
ylabel('Rotations');
legend('Treap','AVL Tree','Location','northeastoutside');
xtips1 = b(1).XEndPoints;
ytips1 = b(1).YEndPoints;
labels1 = string(b(1).YData);
text(xtips1,ytips1,labels1,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips2 = b(2).XEndPoints;
ytips2 = b(2).YEndPoints;
labels2 = string(b(2).YData);
text(xtips2,ytips2,labels2,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')



figure; %line plot
b = bar(c1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
xlabel('Ratio');
title('Ratio vs Height of Tree for 10000 operations');
ylabel('Height of Tree');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');
xtips1 = b(1).XEndPoints;
ytips1 = b(1).YEndPoints;
labels1 = string(b(1).YData);
text(xtips1,ytips1,labels1,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips2 = b(2).XEndPoints;
ytips2 = b(2).YEndPoints;
labels2 = string(b(2).YData);
text(xtips2,ytips2,labels2,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips3 = b(3).XEndPoints;
ytips3 = b(3).YEndPoints;
labels3 = string(b(3).YData);
text(xtips3,ytips3,labels3,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')



figure; %line plot
b = bar(d1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Root for 10000 operations');
xlabel('Ratio');
ylabel('Average Height from Root');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');
xtips1 = b(1).XEndPoints;
ytips1 = b(1).YEndPoints;
labels1 = string(b(1).YData);
text(xtips1,ytips1,labels1,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips2 = b(2).XEndPoints;
ytips2 = b(2).YEndPoints;
labels2 = string(b(2).YData);
text(xtips2,ytips2,labels2,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips3 = b(3).XEndPoints;
ytips3 = b(3).YEndPoints;
labels3 = string(b(3).YData);
text(xtips3,ytips3,labels3,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')



figure; %line plot
b = bar(e1);
xticklabels({'60:40','65:35','70:30','75:25','80:20'});
title('Ratio vs Average Height from Bottom for 10000 operations');
xlabel('Ratio');
ylabel('Average Height from Bottom');
legend('Treap','Binary Search Tree','AVL Tree','Location','northeastoutside');
xtips1 = b(1).XEndPoints;
ytips1 = b(1).YEndPoints;
labels1 = string(b(1).YData);
text(xtips1,ytips1,labels1,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips2 = b(2).XEndPoints;
ytips2 = b(2).YEndPoints;
labels2 = string(b(2).YData);
text(xtips2,ytips2,labels2,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')

xtips3 = b(3).XEndPoints;
ytips3 = b(3).YEndPoints;
labels3 = string(b(3).YData);
text(xtips3,ytips3,labels3,'HorizontalAlignment','center',...
    'VerticalAlignment','bottom')
