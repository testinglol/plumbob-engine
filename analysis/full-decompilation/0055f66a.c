
void __fastcall FUN_0055f66a(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
      *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 0;
    }
    FUN_0057a9a6(0xffffffff);
    (**(code **)(*param_1 + 0x90))(1,0);
    if ((undefined4 *)param_1[0x36] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x36])(1);
    }
    param_1[0x36] = 0;
    if ((undefined4 *)param_1[0x37] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x37])(1);
    }
    param_1[0x37] = 0;
    if ((undefined4 *)param_1[0x38] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x38])(1);
    }
    param_1[0x38] = 0;
    if ((undefined4 *)param_1[0x39] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x39])(1);
    }
    param_1[0x39] = 0;
    if (param_1[0x3a] != 0) {
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      (**(code **)(*piVar2 + 0x14))(param_1[0x3a]);
      param_1[0x3a] = 0;
    }
    _memset(param_1 + 0x3d,0,0x28);
    _memset(param_1 + 0x47,0,0x38);
    FUN_005e63d0(&DAT_006c9c58);
    FUN_005e63d0(s_stream_fps_006cd81c);
    piVar2 = param_1 + 100;
    iVar4 = 3;
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
    *(int *)(DAT_006fe8f4 + 0x1fc) = param_1[0x69];
    FUN_005e47ab(0,0,0,0);
    FUN_005dadbc(0,1);
  }
  FUN_005dbf4d();
  return;
}

