
undefined4 * __thiscall
FUN_00576090(int *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int *local_c;
  int *piStack_8;
  
  iVar1 = *param_1;
  iVar4 = param_3;
  local_c = param_1;
  piStack_8 = param_1;
  if (param_3 == *(int *)(iVar1 + 8)) {
    if ((param_1[1] == 0) || (cVar2 = FUN_00430155(param_4,param_3 + 0x10), cVar2 == '\0'))
    goto LAB_0057614a;
LAB_005760c1:
    FUN_00576d31(param_2,param_3,iVar4,param_4);
  }
  else {
    if (param_3 == iVar1) {
      cVar2 = FUN_00430155(*(int *)(iVar1 + 0xc) + 0x10,param_4);
      if (cVar2 != '\0') {
        iVar4 = *(int *)(*param_1 + 0xc);
LAB_0057613f:
        param_3 = 0;
        goto LAB_005760c1;
      }
    }
    else {
      FUN_0042a392();
      cVar2 = FUN_00430155(param_3 + 0x10,param_4);
      if ((cVar2 != '\0') && (cVar2 = FUN_00430155(param_4,param_3 + 0x10), cVar2 != '\0')) {
        if (*(int *)(param_3 + 0xc) != 0) goto LAB_005760c1;
        goto LAB_0057613f;
      }
    }
LAB_0057614a:
    puVar3 = (undefined4 *)FUN_00576dbf(&local_c,param_4);
    *param_2 = *puVar3;
  }
  return param_2;
}

