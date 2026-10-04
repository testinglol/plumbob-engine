
void __thiscall FUN_004acdcb(int param_1,short *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  float local_8;
  
  if ((*(int *)(param_1 + 0x1bc) != 0) && (*(char *)(param_1 + 0x1c0) != '\0')) {
    local_10 = 0;
    local_c = 0;
    fVar5 = (float10)FUN_004b46a4();
    local_8 = (float)fVar5;
    FUN_004b475c();
    local_1c = (int)*param_2;
    local_14 = (int)param_2[2];
    local_20 = (int)param_2[1];
    local_18 = (int)param_2[3];
    piVar3 = *(int **)(param_1 + 0x1bc);
    piVar4 = (int *)piVar3[100];
    if ((int *)piVar3[100] != (int *)0x0) goto LAB_004ace4b;
    while (piVar4 = piVar3, piVar3 != (int *)0x0) {
LAB_004ace4b:
      local_10 = piVar4[0x3d];
      local_c = piVar4[0x3e];
      cVar1 = FUN_00422665(&local_10);
      if (cVar1 == '\0') {
        iVar2 = piVar4[0x44];
        if (iVar2 == 0) {
          iVar2 = 1;
        }
        uVar7 = 0xffffffff;
        piVar3 = &local_10;
        uVar6 = param_3;
        FUN_004b469d(piVar3,iVar2,param_3,0xffffffff);
        FUN_004b97eb(piVar3,iVar2,uVar6,uVar7);
        FUN_0043908c(1);
        (**(code **)(*piVar4 + 0x30))(&local_20,param_3);
        if ((local_20 < local_18) && (local_1c < local_14)) {
          local_20 = local_20 + DAT_006f0080;
          local_18 = local_18 + DAT_006f0080;
          local_1c = local_1c + DAT_006f0084;
          local_14 = local_14 + DAT_006f0084;
          FUN_004a7901();
          if ((local_20 < local_18) &&
             (((local_1c < local_14 && (*(int *)(param_1 + 0x68) != 0)) && (DAT_006e4870 == '\0'))))
          {
            FUN_005cf0fa(&local_20);
          }
        }
      }
      piVar3 = (int *)piVar4[99];
    }
    FUN_004b4722(local_8);
  }
  return;
}

