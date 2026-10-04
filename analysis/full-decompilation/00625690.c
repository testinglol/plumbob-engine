
int * FUN_00625690(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_10;
  undefined4 local_8;
  int local_4;
  
  piVar3 = param_3;
  piVar2 = param_1;
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar4 = *(int *)(*param_1 + 0x14);
  iVar6 = 0;
  local_4 = iVar4;
  if (iVar4 < 1) {
    return param_3;
  }
  do {
    iVar7 = 0;
    if (0 < iVar1) {
      do {
        iVar4 = *(int *)(*piVar2 + 0x18) * iVar7;
        local_8 = *(undefined4 *)
                   (((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + piVar2[2] * iVar6 + piVar2[1]);
        iVar4 = FUN_006257e0(&local_8,param_2);
        if (iVar4 == 0) {
          param_3 = (int *)0x0;
          iVar5 = *(int *)(*piVar3 + 0x18) * iVar7;
          iVar4 = piVar3[1];
          iVar5 = ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar6;
        }
        else if (iVar4 == 1) {
          iVar5 = *(int *)(*piVar3 + 0x18) * iVar7;
          iVar4 = piVar3[1];
          param_1 = (int *)0xffffffff;
          iVar5 = ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar6;
          param_3 = param_1;
        }
        else {
          iVar5 = *(int *)(*piVar3 + 0x18) * iVar7;
          iVar4 = piVar3[1];
          local_10 = 0x80808080;
          iVar5 = ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + piVar3[2] * iVar6;
          param_3 = (int *)local_10;
        }
        *(int **)(iVar5 + iVar4) = param_3;
        iVar7 = iVar7 + 1;
        iVar4 = local_4;
      } while (iVar7 < iVar1);
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < iVar4);
  return piVar3;
}

