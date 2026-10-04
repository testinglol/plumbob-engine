
void __fastcall FUN_005f1c53(int *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  
  cVar3 = (**(code **)(*param_1 + 200))();
  if (cVar3 != '\0') {
    DAT_006fecb0 = DAT_006fecb0 + -1;
    uVar4 = 0;
    (**(code **)(*(int *)param_1[0x6d] + 0x20))(0,param_1);
    FUN_005ed911();
    param_1[0x6d] = 0;
    piVar1 = param_1 + 0x3c;
    if (param_1[0x3d] - param_1[0x3c] >> 2 != 0) {
      do {
        iVar2 = *(int *)(*piVar1 + uVar4 * 4);
        if (iVar2 != 0) {
          FUN_005f1d92();
          FUN_006321f0(iVar2);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(param_1[0x3d] - *piVar1 >> 2));
    }
    FUN_0052ea87(*piVar1,param_1[0x3d]);
    uVar4 = 0;
    piVar1 = param_1 + 0x5a;
    param_1[0x45] = 0;
    if (param_1[0x5b] - *piVar1 >> 2 != 0) {
      do {
        iVar2 = *(int *)(*piVar1 + uVar4 * 4);
        if (iVar2 != 0) {
          FUN_005f1d9a();
          FUN_006321f0(iVar2);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(param_1[0x5b] - *piVar1 >> 2));
    }
    FUN_0052ea87(*piVar1,param_1[0x5b]);
    piVar1 = param_1 + 0x5d;
    uVar4 = 0;
    if (param_1[0x5e] - *piVar1 >> 2 != 0) {
      do {
        iVar2 = *(int *)(*piVar1 + uVar4 * 4);
        if (iVar2 != 0) {
          FUN_005f1d9a();
          FUN_006321f0(iVar2);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)(param_1[0x5e] - *piVar1 >> 2));
    }
    FUN_0052ea87(*piVar1,param_1[0x5e]);
    if ((undefined4 *)param_1[0x66] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x66])(1);
    }
    param_1[0x66] = 0;
  }
  FUN_005dbf4d();
  return;
}

