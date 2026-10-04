
int __thiscall FUN_00462c01(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_44 [64];
  
  if (*(int *)(param_2 + 0x40) != 1) {
    if (*(int *)(param_1 + 0x40) == 1) {
      FUN_00462f2f(param_2);
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
    }
    else {
      uVar1 = FUN_00462c49(local_44,param_1,param_2);
      FUN_00462f2f(uVar1);
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
  }
  return param_1;
}

