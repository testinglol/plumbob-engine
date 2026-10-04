
void __thiscall FUN_005e297e(int *param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x80))(*param_2,param_2[1],param_2[2],param_2[1],param_3,param_4);
  iVar1 = (param_2[3] - param_4) + 1;
  (**(code **)(*param_1 + 0x80))(*param_2,iVar1,param_2[2],iVar1,param_3,param_4);
  iVar1 = (param_2[2] - param_4) + 1;
  (**(code **)(*param_1 + 0x80))(iVar1,param_2[1],iVar1,param_2[3],param_3,param_4);
  (**(code **)(*param_1 + 0x80))(*param_2,param_2[1],*param_2,param_2[3],param_3,param_4);
  return;
}

