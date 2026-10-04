
void __thiscall
FUN_0048f92b(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  SHORT SVar1;
  undefined4 uVar2;
  
  *(undefined1 *)((int)param_1 + 0x59) = 1;
  FUN_00486459(0);
  if ((char)param_1[0x16] != '\0') {
    (**(code **)(*param_1 + 0x28))(param_2,param_3,param_4,param_5);
    if (param_1[0x12] == 0) {
      if (param_1[0xd] != 0) {
        FUN_00485b4c();
        param_1[0xd] = 0;
      }
    }
    else {
      if ((1 < param_1[0x12]) && (param_1[0xb] != 1)) {
        FUN_0057a7f7(s_UI_bld_dragtool_mouseup_006c5f38,0xfffffffc);
      }
      if (param_1[0xd] != 0) {
        uVar2 = FUN_00461d22();
        FUN_0048fa10(uVar2);
        *(int *)(param_1[0xd] + 0x2c) = param_1[0x12];
        FUN_0049341e(param_1[0xd]);
      }
      FUN_004616c3(param_1[0xe]);
      uVar2 = FUN_00461e56(0,0,0,0,1);
      FUN_0048ec44(uVar2);
      param_1[0x12] = 0;
      FUN_00492bc4();
      FUN_00492c68();
    }
    if (param_1[0xb] == 1) {
      SVar1 = GetAsyncKeyState(0x11);
      if (-1 < SVar1) {
        FUN_004905d0(0);
      }
    }
  }
  return;
}

