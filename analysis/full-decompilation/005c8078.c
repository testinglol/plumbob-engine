
int FUN_005c8078(void)

{
  int xRight;
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar3 = *(int *)(unaff_EBP + 0x20);
  *(undefined4 *)(extraout_ECX + 100) = *(undefined4 *)(unaff_EBP + 0x34);
  *(undefined4 *)(extraout_ECX + 0x68) = *(undefined4 *)(unaff_EBP + 0x38);
  *(undefined1 *)(extraout_ECX + 9) = *(undefined1 *)(unaff_EBP + 0x2c);
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x128) = uVar4;
  *(undefined4 *)(extraout_ECX + 300) = uVar4;
  xRight = *(int *)(unaff_EBP + 0x1c);
  *(int *)(extraout_ECX + 0x48) = xRight;
  *(undefined1 *)(extraout_ECX + 0x4e0) = 0;
  *(undefined4 *)(extraout_ECX + 4) = 0;
  *(undefined4 *)(extraout_ECX + 0x504) = 0;
  *(int *)(extraout_ECX + 0x4c) = iVar3;
  SetRect((LPRECT)(extraout_ECX + 0x28),0,0,xRight,iVar3);
  *(undefined4 *)(extraout_ECX + 0xc) = *(undefined4 *)(unaff_EBP + 0x24);
  *(undefined1 *)(extraout_ECX + 8) = *(undefined1 *)(unaff_EBP + 0x28);
  piVar1 = *(int **)(unaff_EBP + 0xc);
  *(int **)(extraout_ECX + 0x6c) = piVar1;
  (**(code **)(*piVar1 + 4))(piVar1);
  iVar3 = (**(code **)**(undefined4 **)(extraout_ECX + 0x6c))
                    (*(undefined4 **)(extraout_ECX + 0x6c),&DAT_00677338,extraout_ECX + 0x70);
  *(int *)(extraout_ECX + 4) = iVar3;
  if (-1 < iVar3) {
    iVar3 = (**(code **)**(undefined4 **)(extraout_ECX + 0x6c))
                      (*(undefined4 **)(extraout_ECX + 0x6c),&DAT_00677328,extraout_ECX + 0x74);
    *(int *)(extraout_ECX + 4) = iVar3;
    if (-1 < iVar3) {
      _memset((void *)(extraout_ECX + 0x130),0,0x17c);
      *(undefined4 *)(extraout_ECX + 0x130) = 0x17c;
      _memset((void *)(extraout_ECX + 0x2ac),0,0x17c);
      *(undefined4 *)(extraout_ECX + 0x2ac) = 0x17c;
      iVar3 = (**(code **)(**(int **)(extraout_ECX + 0x74) + 0x2c))
                        (*(int **)(extraout_ECX + 0x74),extraout_ECX + 0x130,
                         (undefined4 *)(extraout_ECX + 0x2ac));
      *(int *)(extraout_ECX + 4) = iVar3;
      if (iVar3 == 0) {
        iVar3 = (**(code **)**(undefined4 **)(extraout_ECX + 0x74))
                          (*(undefined4 **)(extraout_ECX + 0x74),&DAT_006772b8,
                           (undefined4 *)(extraout_ECX + 0xa4));
        *(int *)(extraout_ECX + 4) = iVar3;
        if (iVar3 == 0) {
          FUN_005c9897(extraout_ECX + 0x18);
          FUN_005caf77();
          FUN_005c7f9b(0);
          FUN_005ca75e(*(undefined4 *)(unaff_EBP + 0x30));
          piVar1 = *(int **)(unaff_EBP + 0x10);
          (**(code **)(*(int *)(extraout_ECX + 0x78) + 4))(piVar1);
          _memset((void *)(unaff_EBP + -0x8c),0,0x6c);
          iVar3 = *piVar1;
          *(undefined4 *)(unaff_EBP + -0x8c) = 0x6c;
          *(undefined4 *)(unaff_EBP + -0x88) = 6;
          (**(code **)(iVar3 + 0x58))(piVar1,unaff_EBP + -0x8c);
          SetRect((LPRECT)(extraout_ECX + 0x38),0,0,*(int *)(unaff_EBP + -0x80),
                  *(int *)(unaff_EBP + -0x84));
          piVar1 = *(int **)(extraout_ECX + 0x7c);
          *(undefined4 *)(unaff_EBP + 0x28) = 4;
          iVar3 = (**(code **)(*piVar1 + 0x30))(piVar1,unaff_EBP + 0x28,unaff_EBP + 0x2c);
          *(int *)(extraout_ECX + 4) = iVar3;
          if (iVar3 < 0) {
            *(undefined1 *)(extraout_ECX + 0x44d) = 0;
            (**(code **)(*(int *)(extraout_ECX + 0x80) + 4))(0);
            (**(code **)(*(int *)(extraout_ECX + 0x88) + 4))(*(undefined4 *)(unaff_EBP + 0x14));
            *(undefined4 *)(extraout_ECX + 4) = 0;
          }
          else {
            uVar4 = *(undefined4 *)(unaff_EBP + 0x2c);
            *(undefined1 *)(extraout_ECX + 0x44d) = 1;
            (**(code **)(*(int *)(extraout_ECX + 0x80) + 4))(uVar4);
            (**(code **)(*(int *)(extraout_ECX + 0x88) + 4))(*(undefined4 *)(unaff_EBP + 0x14));
            piVar1 = *(int **)(unaff_EBP + 0x2c);
            *(undefined4 *)(extraout_ECX + 4) = 0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          *(byte *)(extraout_ECX + 0x10) = (byte)(*(uint *)(extraout_ECX + 0x134) >> 7) & 1;
          uVar2 = *(uint *)(extraout_ECX + 0x138);
          *(byte *)(extraout_ECX + 0x11) = (byte)(uVar2 >> 9) & 1;
          *(byte *)(extraout_ECX + 0x13) = (byte)(uVar2 >> 0xb) & 1;
          *(byte *)(extraout_ECX + 0x12) = (byte)(uVar2 >> 10) & 1;
          uVar4 = FUN_005c84a9(unaff_EBP + -0x20,extraout_ECX + 0x78);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_005c83e3(uVar4);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005c7c9d();
          uVar4 = FUN_005c84a9(unaff_EBP + -0x20,extraout_ECX + 0x80);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          FUN_005c83e3(uVar4);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005c7c9d();
          uVar4 = FUN_005c84a9(unaff_EBP + -0x20,extraout_ECX + 0x88);
          *(undefined4 *)(unaff_EBP + -4) = 2;
          FUN_005c83e3(uVar4);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005c7c9d();
          if (*(int *)(unaff_EBP + 0x18) == 0) {
            uVar4 = FUN_005c8aa1(extraout_ECX + 0x10c,extraout_ECX + 0x48);
            *(undefined4 *)(extraout_ECX + 4) = uVar4;
            piVar1 = *(int **)(extraout_ECX + 0x104);
            if (piVar1 != (int *)0x0) {
              uVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,*(undefined4 *)(extraout_ECX + 0x110));
              *(undefined4 *)(extraout_ECX + 4) = uVar4;
            }
            uVar4 = FUN_005c841c(unaff_EBP + -0x14,extraout_ECX + 0x10c);
            *(undefined4 *)(unaff_EBP + -4) = 3;
            FUN_005cb642(uVar4);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005cb62e();
          }
          else {
            (**(code **)(*(int *)(extraout_ECX + 0x90) + 4))(*(undefined4 *)(unaff_EBP + 0x18));
          }
          if (*(char *)(extraout_ECX + 8) == '\0') {
            FUN_005cad6f();
          }
          iVar3 = *(int *)(extraout_ECX + 4);
        }
        else {
          *(undefined4 *)(extraout_ECX + 0xa4) = 0;
        }
      }
      goto LAB_005c83d2;
    }
  }
  *(undefined4 *)(extraout_ECX + 0x6c) = 0;
LAB_005c83d2:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar3;
}

