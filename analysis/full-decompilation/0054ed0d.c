
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0054ed0d(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  float10 fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  iVar1 = *(int *)(param_1 + 0xe8);
  FUN_005e3a26();
  cVar2 = '\0';
  if (*(char *)(param_1 + 0x218) != '\0') {
    piVar3 = *(int **)(param_1 + 0x244);
    if (piVar3 == (int *)0x0) {
      if (((*(int *)(param_1 + 0x248) != 0) || (*(int *)(param_1 + 0x24c) != 0)) ||
         (*(int *)(param_1 + 0x250) != 0)) goto LAB_0054ed69;
      piVar3 = *(int **)(param_1 + 0x254);
      if (piVar3 != (int *)0x0) goto LAB_0054ed5a;
    }
    else {
LAB_0054ed5a:
      cVar2 = (**(code **)(*piVar3 + 0x1a0))(param_1);
      cVar2 = '\x01' - (cVar2 != '\0');
LAB_0054ed69:
      *(char *)(param_1 + 0x219) = cVar2;
    }
    if (iVar1 == *(int *)(param_1 + 0xe8)) {
      return;
    }
    if (DAT_006e5490 < *(uint *)(param_1 + 0x228)) {
      uVar7 = 300;
      uVar6 = 0x3f800000;
      uVar8 = DAT_006e5490;
      fVar4 = (float10)FUN_00473496(DAT_006e5490);
      fVar5 = (float)((float10)_DAT_00666748 - fVar4);
      goto LAB_0054edc4;
    }
  }
  uVar7 = 300;
  uVar6 = 0x3f800000;
  fVar5 = 0.0;
  uVar8 = DAT_006e5490;
LAB_0054edc4:
  FUN_004734bd(fVar5,uVar6,uVar7,uVar8);
  return;
}

