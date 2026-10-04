
void __thiscall FUN_004b17e5(int *param_1,int *param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x137) = 1;
  param_1[0x138] = *param_2;
  param_1[0x139] = param_2[1];
  param_1[0x13a] = param_2[2];
  param_1[0x13b] = param_2[3];
  iVar1 = DAT_006f0080;
  iVar2 = -DAT_006f0084;
  param_1[0x139] = param_1[0x139] + iVar2;
  param_1[0x13b] = param_1[0x13b] + iVar2;
  param_1[0x138] = param_1[0x138] + -iVar1;
  param_1[0x13a] = param_1[0x13a] + -iVar1;
  *(undefined1 *)(param_1 + 0x13c) = param_3;
  if (param_4 == 0) {
    FUN_00406466(0,DAT_00666580);
  }
  else {
    FUN_005d4bbf(param_4);
  }
  (**(code **)(*param_1 + 0x48))();
  FUN_0057a7f7(s_ui_camera_photo_006c73bc,0xfffffffc);
  return;
}

