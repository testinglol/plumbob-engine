
void __thiscall FUN_004c79b5(int param_1,int *param_2,undefined4 param_3)

{
  if ((*(byte *)(param_1 + 0x34) & 1) == 0) {
    (**(code **)(*param_2 + 4))(param_1,param_3);
  }
  else {
    (**(code **)(*param_2 + 8))();
  }
  return;
}

