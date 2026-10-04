
void __fastcall FUN_00565340(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    FUN_00568306(param_1[0x43]);
    if ((DAT_006e486c != 0) && (*(int *)(DAT_006e486c + 0x2c) != 0)) {
      *(undefined4 *)(*(int *)(DAT_006e486c + 0x2c) + 0x60) = 0;
    }
    FUN_0057a9a6(0xffffffff);
    (**(code **)(*param_1 + 0x90))(1,0);
    if ((undefined4 *)param_1[0x42] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x42])(1);
    }
    param_1[0x42] = 0;
    if ((undefined4 *)param_1[0xee] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xee])(1);
    }
    param_1[0xee] = 0;
    if ((undefined4 *)param_1[0xef] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xef])(1);
    }
    param_1[0xef] = 0;
    if ((undefined4 *)param_1[0xf0] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xf0])(1);
    }
    param_1[0xf0] = 0;
    if ((undefined4 *)param_1[0xf1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xf1])(1);
    }
    param_1[0xf1] = 0;
    if ((undefined4 *)param_1[0xf2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xf2])(1);
    }
    param_1[0xf2] = 0;
    if (param_1[0xf3] != 0) {
      piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
      (**(code **)(*piVar2 + 0x14))(param_1[0xf3]);
    }
    param_1[0xf3] = 0;
    piVar2 = param_1 + 0xdb;
    iVar4 = 0x12;
    do {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    piVar2 = param_1 + 0x48;
    iVar4 = 6;
    do {
      FUN_004071be(*piVar2,piVar2[1]);
      FUN_004071be(piVar2[3],piVar2[4]);
      FUN_004071be(piVar2[6],piVar2[7]);
      FUN_004071be(piVar2[9],piVar2[10]);
      FUN_004071be(piVar2[0xc],piVar2[0xd]);
      FUN_004071be(piVar2[0xf],piVar2[0x10]);
      piVar2 = piVar2 + 0x18;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    _memset(param_1 + 0xf6,0,0x24);
    _memset(param_1 + 0xff,0,0x14);
    _memset(param_1 + 0x39,0,0x24);
    FUN_005e63d0(&DAT_006c9c58);
    FUN_005e63d0(s_stream_fps_006cd81c);
    FUN_005e63d0(&DAT_006ce210);
    FUN_005e63d0(s_move_lots_006cd7a4);
    uVar3 = FUN_004b469d();
    FUN_005caf28(uVar3);
    FUN_005cddcf(uVar3);
    *(int *)(DAT_006fe8f4 + 0x1fc) = param_1[0x117];
    FUN_005e47ab(0,0,0,0);
    FUN_005dadbc(0,1);
  }
  FUN_005dbf4d();
  return;
}

