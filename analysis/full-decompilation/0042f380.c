
void __thiscall FUN_0042f380(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int **ppiVar6;
  int *piVar7;
  bool bVar8;
  int *local_8;
  
  local_8 = param_1;
  local_8 = (int *)*param_1;
  piVar7 = local_8;
  if ((int *)local_8[1] != (int *)0x0) {
    iVar1 = *param_3;
    piVar4 = (int *)local_8[1];
    do {
      iVar2 = piVar4[4];
      bVar8 = SBORROW4(iVar2,iVar1);
      iVar3 = iVar2 - iVar1;
      if (iVar2 == iVar1) {
        bVar8 = SBORROW4(piVar4[5],param_3[1]);
        iVar3 = piVar4[5] - param_3[1];
      }
      if (bVar8 == iVar3 < 0) {
        piVar5 = (int *)piVar4[2];
        piVar7 = piVar4;
      }
      else {
        piVar5 = (int *)piVar4[3];
      }
      piVar4 = piVar5;
    } while (piVar5 != (int *)0x0);
  }
  if (piVar7 != local_8) {
    iVar1 = *param_3;
    iVar2 = piVar7[4];
    bVar8 = SBORROW4(iVar1,iVar2);
    iVar3 = iVar1 - iVar2;
    if (iVar1 == iVar2) {
      bVar8 = SBORROW4(param_3[1],piVar7[5]);
      iVar3 = param_3[1] - piVar7[5];
    }
    if (bVar8 == iVar3 < 0) {
      ppiVar6 = &param_3;
      goto LAB_0042f3e2;
    }
  }
  ppiVar6 = &local_8;
LAB_0042f3e2:
  *param_2 = *ppiVar6;
  return;
}

