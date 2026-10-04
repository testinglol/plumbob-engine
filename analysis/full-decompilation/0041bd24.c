
undefined4 __thiscall FUN_0041bd24(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int iStack_8;
  
  if (((int)param_2 < 1) || (*(uint *)(param_1 + 0x10) < param_2)) {
    uVar1 = 0;
  }
  else {
    local_c = param_1;
    iStack_8 = param_1;
    FUN_00580a92(&local_c);
    for (iVar2 = 0; (local_c != 0 && (iVar2 < (int)(param_2 - 1))); iVar2 = iVar2 + 1) {
      FUN_00576e56();
    }
    uVar1 = *(undefined4 *)(local_c + 4);
  }
  return uVar1;
}

