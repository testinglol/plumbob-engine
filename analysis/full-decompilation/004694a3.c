
void __thiscall FUN_004694a3(int *param_1,int *param_2,int param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4 == *param_1) || (param_3 != 0)) {
LAB_004694e3:
    iVar2 = FUN_00469548(param_5);
    iVar3 = *param_1;
    *(int *)(param_4 + 8) = iVar2;
    if (param_4 != iVar3) {
      if (param_4 == *(int *)(iVar3 + 8)) {
        *(int *)(iVar3 + 8) = iVar2;
      }
      goto LAB_00469505;
    }
    *(int *)(iVar3 + 4) = iVar2;
  }
  else {
    cVar1 = FUN_00469252(param_4 + 0x10);
    if (cVar1 != '\0') goto LAB_004694e3;
    iVar2 = FUN_00469548(param_5);
    iVar3 = *param_1;
    *(int *)(param_4 + 0xc) = iVar2;
    if (param_4 != *(int *)(iVar3 + 0xc)) goto LAB_00469505;
  }
  *(int *)(iVar3 + 0xc) = iVar2;
LAB_00469505:
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 4) = param_4;
  FUN_00430367(iVar2,iVar3 + 4);
  param_1[1] = param_1[1] + 1;
  *param_2 = iVar2;
  return;
}

