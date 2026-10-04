
void __thiscall FUN_00567f52(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  piVar5 = param_2;
  iVar1 = param_2[0x12];
  iVar2 = param_2[0x15];
  iVar3 = param_2[0x13];
  iVar4 = param_2[0x16];
  param_2 = (int *)0x0;
  if (0 < iVar4) {
    do {
      iVar6 = _rand();
      if (piVar5[0x15] < 1) {
        if (piVar5[0x14] < *(int *)((int)param_2 * 4 + *piVar5)) goto LAB_00567fbb;
      }
      else if (*(int *)((int)param_2 * 4 + *piVar5) < piVar5[0x14]) {
LAB_00567fbb:
        iVar7 = (int)param_2 * 4;
        if ((int)param_2 < iVar4 + -1) {
          *(undefined4 *)(piVar5[0xc] + 4 + iVar7) = 1;
        }
        *(undefined4 *)(piVar5[0xc] + iVar7) = 0;
        *(undefined4 *)(piVar5[9] + iVar7) = 0;
        *(int *)(iVar7 + *piVar5) = iVar3;
        *(int *)(piVar5[3] + iVar7) = iVar1;
        *(undefined4 *)(piVar5[6] + iVar7) = *(undefined4 *)(param_1 + 0x364);
        *(int *)(piVar5[0xf] + iVar7) = (iVar6 % 0x12) / 2;
      }
      iVar6 = (int)param_2 * 4;
      if (*(char *)(param_1 + 0x368) != '\0') {
        if (iVar2 < 0) {
          FUN_0056815a(piVar5,param_2);
        }
        else {
          FUN_00568052(piVar5,param_2);
        }
      }
      FUN_0056826a(*(undefined4 *)(iVar6 + *piVar5),*(undefined4 *)(piVar5[3] + iVar6),
                   *(undefined4 *)(piVar5[0xf] + iVar6),iVar2);
      param_2 = (int *)((int)param_2 + 1);
    } while ((int)param_2 < iVar4);
  }
  return;
}

