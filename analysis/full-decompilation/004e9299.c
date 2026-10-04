
uint FUN_004e9299(undefined4 param_1,int param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2 == 2) {
    param_2 = 0x7d5;
    uVar5 = 4;
  }
  else {
    uVar2 = param_2 - 3;
    if (uVar2 != 0) goto LAB_004e935b;
    param_2 = 0x7d6;
    uVar5 = 5;
  }
  iVar3 = FUN_004e8d49(param_1);
  uVar2 = 0;
  if (iVar3 == 0) {
LAB_004e935b:
    return uVar2 & 0xffffff00;
  }
  if (uVar5 < 7) {
    uVar2 = iVar3 + 0xc + uVar5 * 8;
  }
  else {
    uVar2 = 0;
  }
  if ((uVar2 == 0) || (*(char *)(uVar2 + 4) != '\0')) {
    if (param_4 == '\0') goto LAB_004e935b;
    FUN_004e8d99(param_1,4,0);
  }
  if (uVar5 < 7) {
    iVar6 = iVar3 + 0xc + uVar5 * 8;
  }
  else {
    iVar6 = 0;
  }
  if (iVar6 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004096c2();
  }
  FUN_005a5e48(uVar4);
  cVar1 = FUN_005a5e72();
  if (cVar1 == '\0') {
    FUN_004e939c(iVar3,param_2,param_3);
    uVar2 = FUN_005a5e72();
    if ((char)uVar2 == '\0') {
      if (param_4 == '\0') goto LAB_004e935b;
      FUN_004e8d99(param_1,4,1);
      if (uVar5 < 7) {
        iVar3 = iVar3 + 0xc + uVar5 * 8;
      }
      else {
        iVar3 = 0;
      }
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_004096c2();
      }
      FUN_005a5e48(uVar4);
    }
    else {
      FUN_004e8ada(uVar5,param_3);
    }
  }
  uVar5 = FUN_005a5e72();
  return uVar5;
}

