
void __fastcall FUN_004872c4(int *param_1)

{
  bool bVar1;
  
  if ((int *)param_1[0xc] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xc] + 0xc))();
  }
  if (((*(char *)((int)param_1 + 0x75) == '\0') && (param_1[0xf] != 0)) &&
     (*(int *)(param_1[0xf] + 0x1ac) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((param_1[0xc] != 0) && (bVar1)) {
    *(undefined4 *)(param_1[0xc] + 0x24) = 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (bVar1) {
    FUN_004934bf();
    FUN_0049356e();
  }
  param_1[0xe] = -1;
  param_1[0x1f] = -1;
  param_1[0x11] = 0;
  param_1[0xd] = 1;
  *(undefined1 *)(param_1 + 0x1d) = 0;
  *(undefined1 *)((int)param_1 + 0x77) = 0;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  *(undefined1 *)((int)param_1 + 0x76) = 0;
  *(undefined1 *)((int)param_1 + 0x7b) = 0;
  *(undefined1 *)((int)param_1 + 0x81) = 0;
  *(undefined1 *)(param_1 + 0x22) = 0;
  *(undefined1 *)((int)param_1 + 0x89) = 0;
  param_1[0x24] = 0;
  *(undefined1 *)((int)param_1 + 0x75) = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined1 *)((int)param_1 + 0x95) = 0;
  *(undefined1 *)((int)param_1 + 0x96) = 0;
  *(undefined1 *)((int)param_1 + 0x97) = 1;
  return;
}

