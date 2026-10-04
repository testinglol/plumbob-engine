
char FUN_00494906(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  cVar1 = FUN_0046198c(param_2);
  if (cVar1 == '\0') {
    iVar7 = (int)*param_2;
    iVar2 = (int)*param_1;
    iVar9 = (int)param_2[1];
    iVar8 = (int)param_1[1];
    iVar3 = FUN_00636bef(iVar7 - iVar2);
    iVar4 = FUN_00636bef(iVar9 - iVar8);
    iVar5 = FUN_00636bef((iVar7 - iVar9) - (iVar2 - iVar8));
    iVar5 = iVar5 / 2;
    iVar6 = FUN_00636bef((iVar9 + iVar7) - (iVar8 + iVar2));
    iVar6 = iVar6 / 2;
    if (((iVar3 < iVar4) && (iVar3 <= iVar5)) && (iVar3 <= iVar6)) {
      cVar1 = -1 < iVar9 - iVar8;
    }
    else if (((iVar4 < iVar3) && (iVar4 <= iVar5)) && (iVar4 <= iVar6)) {
      cVar1 = (-1 < iVar7 - iVar2) + '\x02';
    }
    else if (((iVar5 < iVar3) && (iVar5 < iVar4)) && (iVar5 < iVar6)) {
      cVar1 = (iVar8 + iVar2 <= iVar9 + iVar7) + '\x04';
    }
    else {
      cVar1 = (iVar7 - iVar9 < iVar2 - iVar8) + '\x06';
    }
  }
  else {
    cVar1 = '\b';
  }
  return cVar1;
}

