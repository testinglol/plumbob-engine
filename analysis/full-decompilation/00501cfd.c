
bool __thiscall FUN_00501cfd(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 == 0) {
    iVar1 = FUN_004cba72();
    iVar2 = FUN_004cba72();
  }
  else {
    if (*(int *)(param_2 + 0x28) == 0) {
      iVar1 = FUN_00492d2c();
      iVar1 = *(int *)(iVar1 + 8) + -0x400;
    }
    else {
      iVar1 = FUN_00487dc4(*(int *)(param_2 + 0x28),*param_1);
    }
    if (*(int *)(param_3 + 0x28) == 0) {
      iVar2 = FUN_00492d2c();
      iVar2 = *(int *)(iVar2 + 8) + -0x400;
    }
    else {
      iVar2 = FUN_00487dc4(*(int *)(param_3 + 0x28),*param_1);
    }
  }
  return iVar1 < iVar2;
}

