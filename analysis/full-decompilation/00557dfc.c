
void __fastcall FUN_00557dfc(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    FUN_0055e143(param_1[0x65]);
    if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
      *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 0;
    }
    FUN_0057a9a6(0xffffffff);
    (**(code **)(*param_1 + 0x90))(1,0);
    if ((undefined4 *)param_1[0x44] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x44])(1);
    }
    param_1[0x44] = 0;
    if ((undefined4 *)param_1[100] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[100])(1);
    }
    param_1[100] = 0;
    if ((undefined4 *)param_1[0x49] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x49])(1);
    }
    param_1[0x49] = 0;
    if ((undefined4 *)param_1[0x4d] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4d])(1);
    }
    param_1[0x4d] = 0;
    if ((undefined4 *)param_1[0x4a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4a])(1);
    }
    param_1[0x4a] = 0;
    if ((undefined4 *)param_1[0x4b] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4b])(1);
    }
    param_1[0x4b] = 0;
    if ((undefined4 *)param_1[0x4c] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4c])(1);
    }
    param_1[0x4c] = 0;
    if ((undefined4 *)param_1[0x4e] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x4e])(1);
    }
    param_1[0x4e] = 0;
    if (param_1[0x4f] != 0) {
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      (**(code **)(*piVar2 + 0x14))(param_1[0x4f]);
      param_1[0x4f] = 0;
    }
    _memset(param_1 + 0x55,0,0x38);
    _memset(param_1 + 0x39,0,0x1c);
    FUN_0055e540();
    FUN_005e63d0(&DAT_006c9c58);
    FUN_005e63d0(s_stream_fps_006cd81c);
    FUN_005e63d0(s_show_zones_006cdee4);
    FUN_005e63d0(s_show_filter_006cde54);
    FUN_005e63d0(s_nessie_006cd7f4);
    FUN_005e63d0(s_move_lots_006cd7a4);
    piVar2 = param_1 + 0x78;
    iVar4 = 6;
    do {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar3 = FUN_004b469d();
    FUN_005caf28(uVar3);
    FUN_005cddcf(uVar3);
    *(int *)(DAT_006fe8f4 + 0x1fc) = param_1[0x80];
    FUN_005e47ab(0,0,0,0);
    FUN_005dadbc(0,1);
  }
  FUN_005dbf4d();
  return;
}

