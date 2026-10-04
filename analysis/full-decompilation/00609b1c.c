
int __thiscall FUN_00609b1c(int *param_1,char *param_2,int param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  char *local_8;
  
  local_c = 0;
  iVar5 = 0;
  local_8 = param_2;
  if (0 < param_4) {
    while( true ) {
      if ((param_3 <= iVar5) || (*local_8 == '\0')) goto LAB_00609ba2;
      cVar2 = (**(code **)(*param_1 + 0x34))((int)*local_8);
      if (cVar2 != '\0') break;
      iVar3 = FUN_0060a2ba(local_8,param_3 - iVar5);
      iVar1 = iVar3 + iVar5;
      if ((param_3 < iVar1) ||
         (iVar4 = (**(code **)(*param_1 + 0x6c))(local_8,iVar3), param_4 < iVar4 + local_c))
      goto LAB_00609ba2;
      iVar5 = (**(code **)(*param_1 + 0x68))(local_8,iVar3);
      local_c = local_c + iVar5;
      local_8 = local_8 + iVar3;
      iVar5 = iVar1;
      if (param_4 <= local_c) goto LAB_00609ba2;
    }
    iVar5 = iVar5 + 1;
LAB_00609ba2:
    if (iVar5 != 0) goto LAB_00609bdd;
  }
  if (param_3 < 1) {
    return iVar5;
  }
  do {
    if (((param_2[iVar5] == '\0') ||
        (cVar2 = (**(code **)(*param_1 + 0x34))((int)param_2[iVar5]), cVar2 != '\0')) ||
       (cVar2 = (**(code **)(*param_1 + 0x38))((int)param_2[iVar5]), cVar2 != '\0')) break;
    iVar5 = iVar5 + 1;
  } while (iVar5 < param_3);
LAB_00609bdd:
  while ((iVar5 < param_3 &&
         (cVar2 = (**(code **)(*param_1 + 0x38))((int)param_2[iVar5]), cVar2 != '\0'))) {
    iVar5 = iVar5 + 1;
  }
  if ((iVar5 == 0) && (0 < param_3)) {
    iVar5 = 1;
  }
  return iVar5;
}

