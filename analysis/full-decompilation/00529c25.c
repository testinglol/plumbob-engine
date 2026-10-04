
void __fastcall FUN_00529c25(int *param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 != '\0') {
    if ((undefined4 *)param_1[0x4a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4a])(1);
    }
    param_1[0x4a] = 0;
    if ((undefined4 *)param_1[0x4b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4b])(1);
    }
    param_1[0x4b] = 0;
    param_1[0x49] = 0;
    piVar1 = param_1 + 0x41;
    uVar3 = 0;
    if (param_1[0x42] - *piVar1 >> 2 != 0) {
      do {
        if (*(int *)(*piVar1 + uVar3 * 4) != 0) {
          FUN_005e3581();
          *(undefined4 *)(*piVar1 + uVar3 * 4) = 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)(param_1[0x42] - *piVar1 >> 2));
    }
    FUN_0052ea87(*piVar1,param_1[0x42]);
  }
  FUN_005dbf4d();
  return;
}

