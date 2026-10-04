
void FUN_00643c14(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_c [8];
  
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
     (iVar1 = _strcmp(param_1,"ACP"), iVar1 == 0)) {
    uVar2 = 0x1004;
  }
  else {
    iVar1 = _strcmp(param_1,(char *)&PTR_LAB_00689bf8);
    if (iVar1 != 0) goto LAB_00643c70;
    uVar2 = 0xb;
  }
  iVar1 = (*DAT_00703c48)(DAT_00703c44,uVar2,local_c,8);
  if (iVar1 == 0) {
    return;
  }
  param_1 = local_c;
LAB_00643c70:
  FUN_00635ed7(param_1);
  return;
}

