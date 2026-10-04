
void FUN_004ab154(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*param_1 < param_1[2]) && (param_1[1] < param_1[3])) {
    FUN_005de822(param_1);
    iVar1 = local_14 + DAT_006f0080;
    iVar2 = local_c + DAT_006f0080;
    iVar3 = local_10 + DAT_006f0084;
    iVar4 = local_8 + DAT_006f0084;
    FUN_004a7901();
    if ((iVar1 < iVar2) && (iVar3 < iVar4)) {
      uVar6 = FUN_004b469d();
      uVar5 = DAT_006fe838;
      DAT_006fe838 = DAT_006d6180;
      FUN_005cddcf(uVar6);
      DAT_006fe838 = uVar5;
    }
  }
  return;
}

