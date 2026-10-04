
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005de28e(int *param_1,char param_2,undefined1 param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  float10 fVar7;
  undefined4 uVar8;
  uint uVar9;
  
  if ((param_1[0x2d] != 0) && ((uint)param_1[0x32] <= DAT_006e5490)) {
    if (param_1[0x2d] < 0) {
      (**(code **)(*param_1 + 0x98))();
    }
    iVar3 = (**(code **)(*param_1 + 0x18))();
    if (iVar3 != 0) {
      iVar3 = param_1[0x2d];
      iVar4 = (**(code **)(*param_1 + 0x18))();
      if (iVar4 != 0) {
        FUN_005da644(iVar4,0x1b,param_1,iVar3,0);
      }
    }
    param_1[0x2d] = 0;
    if ((undefined4 *)param_1[0x34] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x34])(1);
    }
    param_1[0x34] = 0;
    if ((char)param_1[0x33] == '\0') {
      (**(code **)(*param_1 + 0x174))(0,0);
    }
  }
  cVar2 = (**(code **)(*param_1 + 0x8c))(1);
  if ((param_2 != cVar2) || ((param_2 != '\0' && (param_1[0x2d] < 0)))) {
    iVar3 = param_1[0x2d];
    if (param_2 == '\0') {
      if (iVar3 < 0) {
        return;
      }
    }
    else if (0 < iVar3) {
      return;
    }
    if (param_4 == 0) {
      param_4 = 0x14d;
    }
    if (iVar3 == 0) {
      piVar6 = *(int **)param_1[0xe];
      if (piVar6 != (int *)param_1[0xe]) {
        do {
          (**(code **)(*(int *)piVar6[2] + 0xac))();
          piVar6 = (int *)*piVar6;
        } while (piVar6 != (int *)param_1[0xe]);
      }
      *(undefined1 *)((int)param_1 + 0xcd) = param_3;
      *(bool *)(param_1 + 0x33) = param_1[0x16] != 0;
      if (param_1[0x16] == 0) {
        (**(code **)(*param_1 + 0x174))(1,0);
      }
      if (param_2 == '\0') {
        param_1[0x2d] = -1;
        FUN_004734bd(0x3f800000,0,param_4,DAT_006e5490);
      }
      else {
        param_1[0x2d] = 1;
        FUN_004734bd(0,0x3f800000,param_4,DAT_006e5490);
        (**(code **)(*param_1 + 0x94))();
      }
      iVar3 = (**(code **)(*param_1 + 0x18))();
      if (iVar3 != 0) {
        piVar6 = (int *)(**(code **)(*param_1 + 0x18))();
        (**(code **)(*piVar6 + 0x168))();
      }
      (**(code **)(*param_1 + 0x168))();
    }
    else if (iVar3 < 0) {
      FUN_00473496(DAT_006e5490);
      uVar1 = DAT_006e5490;
      uVar9 = DAT_006e5490;
      uVar5 = __ftol(DAT_006e5490);
      uVar8 = 0x3f800000;
      fVar7 = (float10)FUN_00473496(uVar1);
      FUN_004734bd((float)((float10)_DAT_00666748 - fVar7),uVar8,uVar5,uVar9);
      param_1[0x2d] = 1;
    }
    else {
      FUN_00473496(DAT_006e5490);
      uVar1 = DAT_006e5490;
      uVar9 = DAT_006e5490;
      uVar5 = __ftol(DAT_006e5490);
      uVar8 = 0;
      fVar7 = (float10)FUN_00473496(uVar1);
      FUN_004734bd((float)fVar7,uVar8,uVar5,uVar9);
      param_1[0x2d] = -1;
    }
  }
  return;
}

