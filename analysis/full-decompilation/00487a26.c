
void __thiscall FUN_00487a26(int *param_1,short param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_2;
  param_1[0xe] = iVar2;
  (**(code **)(*param_1 + 0x60))();
  *(undefined1 *)((int)param_1 + 0xad) = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  if (param_2 == -1) {
    iVar1 = 0;
    param_1[0xd] = 1;
    *(undefined1 *)((int)param_1 + 0x75) = 0;
    *(undefined1 *)((int)param_1 + 0x76) = 0;
    *(undefined1 *)((int)param_1 + 0x77) = 0;
    *(undefined1 *)(param_1 + 0x1e) = 1;
    *(undefined1 *)(param_1 + 0x25) = 0;
    param_1[0x11] = 0;
  }
  else {
    iVar1 = FUN_00487be9(iVar2);
    if (iVar1 == 0) {
      iVar1 = FUN_00487be9(iVar2);
      if (iVar1 == 0) {
        iVar1 = FUN_00487be9(iVar2);
        if (iVar1 != 0) {
          param_1[0xd] = 5;
          goto LAB_00487b51;
        }
        iVar1 = FUN_00487be9(iVar2);
        if (iVar1 != 0) {
          param_1[0xd] = 6;
          *(undefined1 *)((int)param_1 + 0x75) = 1;
          *(undefined1 *)((int)param_1 + 0x76) = 1;
          *(undefined1 *)((int)param_1 + 0x77) = 1;
          *(undefined1 *)(param_1 + 0x1e) = 0;
          *(undefined1 *)(param_1 + 0x25) = 0;
          *(undefined1 *)((int)param_1 + 0xad) = 1;
          goto LAB_00487b98;
        }
        iVar1 = FUN_00487be9(iVar2);
        if (iVar1 == 0) {
          iVar1 = FUN_00487be9(iVar2);
          if (iVar1 != 0) {
            param_1[0xd] = 8;
            goto LAB_00487b51;
          }
          iVar1 = FUN_00487be9(iVar2);
          if (iVar1 != 0) {
            param_1[0xd] = 9;
            goto LAB_00487b51;
          }
          iVar1 = FUN_0043ad1f(iVar2);
          if (iVar1 == 0) {
            param_1[0xd] = 1;
            *(undefined1 *)((int)param_1 + 0x75) = 0;
          }
          else {
            param_1[0xd] = 2;
            *(undefined1 *)((int)param_1 + 0x75) = 1;
          }
          *(undefined1 *)((int)param_1 + 0x76) = 0;
          *(undefined1 *)((int)param_1 + 0x77) = 0;
        }
        else {
          param_1[0xd] = 7;
LAB_00487b51:
          *(undefined1 *)((int)param_1 + 0x75) = 1;
          *(undefined1 *)((int)param_1 + 0x76) = 1;
          *(undefined1 *)((int)param_1 + 0x77) = 1;
        }
        *(undefined1 *)(param_1 + 0x1e) = 1;
        *(undefined1 *)(param_1 + 0x25) = 0;
        goto LAB_00487b98;
      }
      param_1[0xd] = 4;
    }
    else {
      param_1[0xd] = 3;
    }
    *(undefined1 *)((int)param_1 + 0x75) = 1;
    *(undefined1 *)((int)param_1 + 0x76) = 1;
    *(undefined1 *)((int)param_1 + 0x77) = 1;
    *(undefined1 *)(param_1 + 0x1e) = 1;
    *(undefined1 *)(param_1 + 0x25) = 0;
    *(undefined1 *)(param_1 + 10) = 1;
  }
LAB_00487b98:
  if (iVar1 != param_1[0x11]) {
    param_1[0x11] = iVar1;
    if (iVar1 != 0) {
      if ((*(short *)(*(int *)(iVar1 + 0x60) + 0xc0) == 1) &&
         (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x44) == 0)) {
        *(undefined1 *)((int)param_1 + 0x76) = 1;
      }
      if (*(short *)(*(int *)(iVar1 + 0x60) + 0x8a) != 0) {
        param_1[9] = 7;
        goto LAB_00487bdc;
      }
    }
    param_1[9] = 6;
  }
LAB_00487bdc:
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  return;
}

