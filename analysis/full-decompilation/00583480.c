
char FUN_00583480(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = '\x01';
  if (param_2 < 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 8);
    if ((param_2 <= iVar3) || (*(int *)(param_1 + 0x18) != 0)) {
      iVar3 = param_2 - *(int *)(param_1 + 4);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar3;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iVar3;
      goto LAB_005834a5;
    }
  }
  cVar2 = '\0';
  *(int *)(param_1 + 4) = iVar3;
  *(int *)(param_1 + 0x10) = param_1 + 0x424;
  *(int *)(param_1 + 0x14) = param_1 + 0x424;
  param_2 = iVar3;
LAB_005834a5:
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar3 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
    if (((iVar3 < 1) || (0x2000 < iVar3)) || ((*(int *)(param_1 + 0x10) - param_1) + -0x424 < 0)) {
      if ((param_2 < 0) || (*(int *)(param_1 + 8) < param_2)) {
        cVar2 = '\0';
      }
      else {
        cVar2 = FUN_005b8f4a(param_2);
      }
      *(int *)(param_1 + 0x10) = param_1 + 0x424;
      *(int *)(param_1 + 0x14) = param_1 + 0x424;
    }
  }
  else {
    cVar1 = FUN_005b8f4a(param_2);
    if ((cVar1 == '\0') || (cVar2 == '\0')) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x01';
    }
  }
  return cVar2;
}

