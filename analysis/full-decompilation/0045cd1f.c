
void __thiscall FUN_0045cd1f(int param_1,undefined4 param_2,ushort *param_3)

{
  ushort *puVar1;
  ushort uVar2;
  
  puVar1 = param_3 + 2;
  uVar2 = *param_3 & 0x7fff;
  if (uVar2 < 0x1e) {
    if (uVar2 == 0x1d) {
      FUN_0045a2db(param_2,puVar1);
      return;
    }
    if (uVar2 == 3) {
      FUN_0045dea5(param_2);
      return;
    }
    if (uVar2 == 6) {
      FUN_0045dace(param_2,puVar1);
      return;
    }
    if (uVar2 == 0x11) {
      FUN_0045dd00(param_2,puVar1);
      return;
    }
    if (uVar2 == 0x16) {
      FUN_0045aafa(param_2,puVar1);
      return;
    }
    if (uVar2 == 0x1b) {
      FUN_0045c7a0(param_2,puVar1);
      return;
    }
  }
  else {
    if (uVar2 == 0x1e) {
      FUN_0045a9c5(param_2);
      return;
    }
    if (uVar2 == 0x25) {
      FUN_0045d9eb(param_2,puVar1);
      return;
    }
    if (uVar2 == 0x2c) {
      (**(code **)(**(int **)(param_1 + 0xadc) + 0x28))(param_2,puVar1);
      return;
    }
    if (uVar2 == 0x2d) {
      FUN_0045ad3a(param_2,puVar1);
      return;
    }
    if (uVar2 == 0x2f) {
      FUN_0045cb26(param_2,puVar1);
      return;
    }
  }
  FUN_00452288(param_2,param_3);
  return;
}

