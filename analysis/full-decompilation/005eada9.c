
void __thiscall
FUN_005eada9(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5,
            undefined4 param_6,int param_7,int param_8,undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  
  (**(code **)(*param_1 + 0x19c))(param_6,param_7,param_8,param_9,param_10);
  uVar1 = (**(code **)(*param_4 + 0x1c))();
  (**(code **)(*param_4 + 0x20))(param_5);
  (**(code **)(*param_4 + 0x78))
            (param_1[0x17],param_1[7] + 3 + param_7,param_1[8] + 3 + param_8,param_2,param_3,0,0,0);
  (**(code **)(*param_4 + 0x20))(uVar1);
  return;
}

