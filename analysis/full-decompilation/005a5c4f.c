
void __thiscall FUN_005a5c4f(int *param_1,int *param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  
  if (((param_4 == *param_1) || (param_3 != 0)) || (*param_5 < *(uint *)(param_4 + 0x10))) {
    iVar1 = FUN_005a5d5c(param_5);
    *(int *)(param_4 + 8) = iVar1;
    iVar2 = *param_1;
    if (param_4 != iVar2) {
      if (param_4 == *(int *)(iVar2 + 8)) {
        *(int *)(iVar2 + 8) = iVar1;
      }
      goto LAB_005a5ca9;
    }
    *(int *)(iVar2 + 4) = iVar1;
    iVar2 = *param_1;
  }
  else {
    iVar1 = FUN_005a5d5c(param_5);
    *(int *)(param_4 + 0xc) = iVar1;
    iVar2 = *param_1;
    if (param_4 != *(int *)(iVar2 + 0xc)) goto LAB_005a5ca9;
  }
  *(int *)(iVar2 + 0xc) = iVar1;
LAB_005a5ca9:
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(int *)(iVar1 + 4) = param_4;
  FUN_00430367(iVar1,*param_1 + 4);
  param_1[1] = param_1[1] + 1;
  *param_2 = iVar1;
  return;
}

