
void __fastcall FUN_00513488(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int local_8;
  
  cVar3 = (**(code **)(*param_1 + 200))();
  if (cVar3 != '\0') {
    if ((undefined4 *)param_1[0x68] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x68])(1);
    }
    param_1[0x68] = 0;
    FUN_006321f0(param_1[0x6a]);
    param_1[0x6a] = 0;
    FUN_006321f0(param_1[0x6b]);
    param_1[0x6b] = 0;
    param_1[0x6c] = 0;
    piVar1 = param_1 + 0x6d;
    local_8 = 0;
    iVar4 = param_1[0x6e] - *piVar1 >> 2;
    if (0 < iVar4) {
      do {
        puVar2 = *(undefined4 **)(*piVar1 + local_8 * 4);
        if (puVar2 != (undefined4 *)0x0) {
          (**(code **)*puVar2)(1);
        }
        local_8 = local_8 + 1;
      } while (local_8 < iVar4);
    }
    FUN_0052ea87(*piVar1,param_1[0x6e]);
  }
  FUN_005e38e0();
  return;
}

