
void FUN_00612560(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  piVar1 = param_2;
  iVar5 = *(int *)(*param_2 + 0x10);
  iVar6 = *(int *)(*param_2 + 0x14);
  iVar4 = 0;
  local_8 = 0;
  local_4 = 0;
  uVar2 = FUN_00612680(param_2,0,0);
  if (0 < iVar5) {
    do {
      iVar3 = FUN_006126e0(param_2,iVar4,0,iVar6,uVar2);
      if (iVar3 == 0) {
        iVar5 = iVar5 - iVar4;
        local_8 = iVar4;
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  for (iVar4 = iVar5 + -1 + local_8; local_8 <= iVar4; iVar4 = iVar4 + -1) {
    iVar3 = FUN_006126e0(param_2,iVar4,0,iVar6,uVar2);
    if (iVar3 == 0) {
      iVar5 = (iVar4 - local_8) + 1;
      break;
    }
  }
  iVar4 = 0;
  if (0 < iVar6) {
    do {
      iVar3 = FUN_00612750(param_2,iVar4,local_8,iVar5,uVar2);
      if (iVar3 == 0) {
        iVar6 = iVar6 - iVar4;
        local_4 = iVar4;
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar6);
  }
  param_2 = (int *)iVar6;
  iVar6 = (int)param_2 + -1 + local_4;
  do {
    if (iVar6 < local_4) {
LAB_00612654:
      *param_1 = local_8;
      param_1[2] = iVar5;
      param_1[1] = local_4;
      param_1[3] = (int)param_2;
      return;
    }
    iVar4 = FUN_00612750(piVar1,iVar6,local_8,iVar5,uVar2);
    if (iVar4 == 0) {
      param_2 = (int *)((iVar6 - local_4) + 1);
      goto LAB_00612654;
    }
    iVar6 = iVar6 + -1;
  } while( true );
}

