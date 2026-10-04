
void FUN_00403c9d(char *param_1,int *param_2,int *param_3)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined1 *local_1c;
  undefined1 local_14 [16];
  
  if (param_1 != (char *)0x0) {
    iVar3 = 0;
    sVar1 = _strlen(param_1);
    if (0 < (int)sVar1) {
      do {
        if ((param_1[iVar3] == 'a') || (param_1[iVar3] == 'p')) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)sVar1);
    }
    FUN_0046f824(local_14,0,0x10);
    FUN_0046f847(param_1,iVar3);
    iVar2 = FUN_00635f62(local_1c);
    *param_2 = iVar2;
    if (iVar2 == 0xc) {
      *param_2 = 0;
    }
    if (iVar3 < (int)sVar1) {
      if (param_1[iVar3] == 'p') {
        *param_2 = *param_2 + 0xc;
      }
      do {
        if (param_1[iVar3] == '-') break;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)sVar1);
    }
    iVar3 = iVar3 + 1;
    for (iVar2 = iVar3; ((iVar2 < (int)sVar1 && (param_1[iVar2] != 'a')) && (param_1[iVar2] != 'p'))
        ; iVar2 = iVar2 + 1) {
    }
    *local_1c = 0;
    FUN_0046f847(param_1 + iVar3,iVar2 - iVar3);
    iVar3 = FUN_00635f62(local_1c);
    *param_3 = iVar3;
    if (iVar3 == 0xc) {
      *param_3 = 0;
    }
    if ((iVar2 < (int)sVar1) && (param_1[iVar2] == 'p')) {
      *param_3 = *param_3 + 0xc;
    }
  }
  return;
}

