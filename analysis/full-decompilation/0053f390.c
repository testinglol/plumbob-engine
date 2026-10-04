
char FUN_0053f390(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  cVar1 = FUN_0046198c(param_2);
  if (cVar1 == '\0') {
    iVar6 = (int)*param_2;
    iVar2 = (int)*param_1;
    iVar12 = (int)param_2[1];
    uVar8 = iVar6 - iVar2;
    iVar9 = (int)param_1[1];
    uVar11 = iVar12 - iVar9;
    iVar13 = (uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f);
    uVar3 = (iVar6 - iVar12) - (iVar2 - iVar9);
    iVar14 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
    uVar10 = (int)uVar3 >> 0x1f;
    uVar4 = (iVar12 + iVar6) - (iVar9 + iVar2);
    iVar7 = (int)((uVar3 ^ uVar10) - uVar10) / 2;
    uVar3 = (int)uVar4 >> 0x1f;
    iVar5 = (int)((uVar4 ^ uVar3) - uVar3) / 2;
    if (((iVar13 < iVar14) && (iVar13 <= iVar7)) && (iVar13 <= iVar5)) {
      cVar1 = -1 < (int)uVar11;
    }
    else if (((iVar14 < iVar13) && (iVar14 <= iVar7)) && (iVar14 <= iVar5)) {
      cVar1 = (-1 < (int)uVar8) + '\x02';
    }
    else if (((iVar7 < iVar13) && (iVar7 < iVar14)) && (iVar7 < iVar5)) {
      cVar1 = (iVar9 + iVar2 <= iVar12 + iVar6) + '\x04';
    }
    else {
      cVar1 = (iVar6 - iVar12 < iVar2 - iVar9) + '\x06';
    }
  }
  else {
    cVar1 = '\b';
  }
  return cVar1;
}

