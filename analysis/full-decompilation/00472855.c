
void __thiscall FUN_00472855(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *param_1;
  iVar1 = (param_1[1] - iVar2) / 0x14;
  if (iVar2 != param_1[1]) {
    do {
      if (*(int *)(iVar2 + 0xc) == -1) {
        *(int *)(iVar2 + 0xc) = iVar1;
      }
      if (*(int *)(iVar2 + 0x10) == -1) {
        *(int *)(iVar2 + 0x10) = iVar1;
      }
      iVar2 = iVar2 + 0x14;
    } while (iVar2 != param_1[1]);
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = param_2 + 2;
  local_c = 0xffffffff;
  local_8 = 0xffffffff;
  FUN_00472b86(&local_18);
  return;
}

