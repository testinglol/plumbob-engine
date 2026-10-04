
undefined4 __fastcall FUN_00505e06(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 != '\0') {
    (**(code **)(*param_1 + 0x90))(1,0);
    if (param_1[0x10b] != 0) {
      FUN_0050848f();
      FUN_005da4c7(param_1[0x10b]);
      param_1[0x10b] = 0;
    }
    piVar5 = param_1 + 0x39;
    iVar3 = 2;
    do {
      cVar2 = (**(code **)(*param_1 + 0x38))(*piVar5);
      if (cVar2 != '\0') {
        (**(code **)(*param_1 + 0x24))(*piVar5);
      }
      FUN_005da4c7(*piVar5);
      *piVar5 = 0;
      if ((undefined4 *)piVar5[-2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar5[-2])(1);
      }
      piVar5[-2] = 0;
      piVar5 = piVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    piVar5 = param_1 + 0x3b;
    iVar3 = 7;
    do {
      iVar4 = 8;
      do {
        if ((undefined4 *)*piVar5 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar5)(1);
          *piVar5 = 0;
        }
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    cVar2 = (**(code **)(*param_1 + 0x38))(param_1[0x73]);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(param_1[0x73]);
    }
    FUN_005da4c7(param_1[0x73]);
    piVar5 = param_1 + 0xdc;
    param_1[0x73] = 0;
    iVar3 = 0;
    piVar7 = param_1 + 0x100;
    do {
      cVar2 = (**(code **)(*param_1 + 0x38))(*piVar7);
      if (cVar2 != '\0') {
        (**(code **)(*param_1 + 0x24))(*piVar7);
      }
      FUN_005da4c7(*piVar7);
      *piVar7 = 0;
      puVar1 = (undefined4 *)piVar7[-0x8c];
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      piVar7[-0x8c] = 0;
      if ((undefined4 *)piVar7[-0x84] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar7[-0x84])(1);
      }
      piVar7[-0x84] = 0;
      if ((undefined4 *)piVar7[-0x54] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar7[-0x54])(1);
      }
      piVar7[-0x54] = 0;
      if ((undefined4 *)piVar7[-0x4c] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar7[-0x4c])(1);
      }
      piVar7[-0x4c] = 0;
      if ((undefined4 *)piVar7[-0x44] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar7[-0x44])(1);
      }
      piVar7[-0x44] = 0;
      if ((undefined4 *)piVar7[-0x3c] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar7[-0x3c])(1);
      }
      piVar7[-0x3c] = 0;
      if ((undefined4 *)piVar7[-0x34] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar7[-0x34])(1);
      }
      piVar7[-0x34] = 0;
      if ((undefined4 *)piVar7[-0x2c] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar7[-0x2c])(1);
      }
      piVar7[-0x2c] = 0;
      if (((iVar3 != 4) && (iVar3 != 5)) && (iVar3 != 6)) {
        if ((undefined4 *)piVar7[-0x7c] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar7[-0x7c])(1);
        }
        piVar7[-0x7c] = 0;
        if ((undefined4 *)piVar7[-0x74] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar7[-0x74])(1);
        }
        piVar7[-0x74] = 0;
        if ((undefined4 *)piVar7[-0x6c] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar7[-0x6c])(1);
        }
        piVar7[-0x6c] = 0;
        if ((undefined4 *)piVar7[-100] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar7[-100])(1);
        }
        piVar7[-100] = 0;
        if ((undefined4 *)piVar7[-0x5c] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar7[-0x5c])(1);
        }
        piVar7[-0x5c] = 0;
      }
      iVar4 = 4;
      do {
        if ((undefined4 *)*piVar5 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar5)(1);
        }
        *piVar5 = 0;
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      iVar3 = iVar3 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar3 < 8);
    if ((undefined4 *)param_1[0xfe] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xfe])(1);
    }
    param_1[0xfe] = 0;
    if ((undefined4 *)param_1[0xff] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xff])(1);
    }
    param_1[0xff] = 0;
    if ((undefined4 *)param_1[0xfc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xfc])(1);
    }
    param_1[0xfc] = 0;
    if ((undefined4 *)param_1[0xfd] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xfd])(1);
    }
    param_1[0xfd] = 0;
    uVar6 = 0;
    if (param_1[0x109] - param_1[0x108] >> 2 != 0) {
      do {
        if (*(int *)(param_1[0x108] + uVar6 * 4) != 0) {
          iVar3 = FUN_00492d2c();
          if (iVar3 != 0) {
            cVar2 = (**(code **)(*param_1 + 0x38))(iVar3);
            if (cVar2 != '\0') {
              (**(code **)(*param_1 + 0x24))(iVar3);
              *(undefined4 *)(param_1[0x108] + uVar6 * 4) = 0;
            }
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)(param_1[0x109] - param_1[0x108] >> 2));
    }
    FUN_005dbf4d();
  }
  return 1;
}

