
uint __thiscall FUN_0045cb26(int param_1,int *param_2,short *param_3)

{
  bool bVar1;
  int *piVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar6;
  short *psVar7;
  uint uVar8;
  char *pcVar9;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  psVar7 = param_3;
  piVar2 = param_2;
  iVar5 = param_2[2];
  if (iVar5 == 0) {
    iVar5 = FUN_0045c9b4(param_2,param_3,&param_2,&local_10,&local_c,&local_14);
    if (iVar5 == 0) {
      return 0;
    }
    sVar4 = FUN_00589ef7(local_14,1);
    if (sVar4 != 0) {
      piVar2[2] = 1;
      return 2;
    }
LAB_0045cbeb:
    return (uint)(psVar7[1] == 0);
  }
  if (iVar5 != 1) {
    if (iVar5 == 2) {
      iVar5 = FUN_0058a004();
      if (iVar5 == 0) {
        return 2;
      }
      uVar8 = 1;
    }
    else {
      if (iVar5 != 3) {
        return 0xffffffff;
      }
      iVar5 = FUN_0058a004();
      if (iVar5 == 0) {
        return 2;
      }
      uVar8 = 0;
    }
    FUN_0058a011();
    return uVar8;
  }
  local_8 = -1;
  bVar1 = false;
  while (iVar5 = (**(code **)(**(int **)(param_1 + 0xadc) + 0x80))(&local_8), iVar5 != 0) {
    if (local_8 == 0) {
      bVar1 = true;
    }
  }
  iVar5 = FUN_0058a004();
  psVar7 = param_3;
  if (iVar5 != 0) {
    bVar1 = true;
  }
  if (!bVar1) {
    return 2;
  }
  iVar5 = FUN_0045c9b4(piVar2,param_3,&param_2,&local_10,&local_c,&local_14);
  if (iVar5 == 0) goto LAB_0045cbeb;
  if (param_3[1] == 0) {
LAB_0045cccc:
    piVar2[2] = 2;
  }
  else {
    if (*param_3 == 0) {
      cVar3 = (**(code **)(*param_2 + 0x54))
                        (param_1 + 0xf4,*(undefined4 *)(param_1 + 0x110),param_1,0);
      if (cVar3 != '\0') {
        (**(code **)(*param_2 + 0x58))(param_1 + 0xf4,*(undefined4 *)(param_1 + 0x110),param_1,0,1);
        pcVar9 = s_CT___Grab_006c4590;
        uVar6 = extraout_var;
LAB_0045ccb1:
        FUN_00452c2d(*(undefined4 *)(param_2[0x47] + 0xc),CONCAT22(uVar6,(short)param_2[0x3c]),
                     pcVar9,0);
        goto LAB_0045cccc;
      }
    }
    else {
      if (*param_3 != 1) {
        return 2;
      }
      param_3 = *(short **)(local_10 + 0x110);
      if ((param_2 != (int *)0x0) &&
         (cVar3 = (**(code **)(*param_2 + 0x54))(local_10 + 0xf4,param_3,local_10,local_c),
         cVar3 != '\0')) {
        (**(code **)(*param_2 + 0x58))(local_10 + 0xf4,param_3,local_10,local_c,1);
        pcVar9 = s_CT___Put_006c4584;
        uVar6 = extraout_var_00;
        goto LAB_0045ccb1;
      }
    }
    piVar2[2] = 3;
  }
  return 2;
}

