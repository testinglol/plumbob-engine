
int FUN_0047870b(void)

{
  undefined1 uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined1 *puVar7;
  int iVar8;
  
  FUN_00634c24();
  iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,0,0);
  if ((iVar2 == 0) &&
     (iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,4,0), iVar2 == 0)) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    iVar8 = extraout_ECX + 0x44;
    *(int *)(unaff_EBP + -0x24) = iVar8;
    do {
      if ((*(int *)(unaff_EBP + -0x18) < 1) || (0x16 < *(int *)(unaff_EBP + 0xc))) {
        if (*(int *)(unaff_EBP + 0xc) < 0x3f) {
          pvVar3 = operator_new(0x20);
          *(void **)(unaff_EBP + -0x20) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          if (pvVar3 == (void *)0x0) {
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          }
          else {
            uVar4 = FUN_0047c8fb(0x40);
            *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,
                               *(int *)(unaff_EBP + -0x18) + 1,0);
          if (iVar2 != 0) goto LAB_00478a6a;
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          iVar2 = *(int *)(extraout_ECX + 0x10);
          if (0 < iVar2) {
            do {
              *(undefined4 *)(unaff_EBP + -0x10) = 0;
              if (0 < iVar2) {
                do {
                  uVar4 = FUN_0047c7b7(unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + -0x10));
                  *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
                  *(undefined4 *)(unaff_EBP + -4) = 1;
                  piVar5 = (int *)FUN_0047c7b7(unaff_EBP + -0x2c,*(undefined4 *)(unaff_EBP + -0x10))
                  ;
                  iVar2 = *piVar5;
                  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
                  *(ushort *)(iVar2 + *(int *)(unaff_EBP + -0x14) * 2) =
                       (ushort)*(byte *)(**(int **)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x14)
                                        );
                } while (*(int *)(unaff_EBP + -0x10) < *(int *)(extraout_ECX + 0x10));
              }
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
              iVar2 = *(int *)(extraout_ECX + 0x10);
            } while (*(int *)(unaff_EBP + -0x14) < iVar2);
          }
          if (*(int *)(unaff_EBP + -0x1c) != 0) {
            FUN_00431242();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x1c));
          }
          pvVar3 = operator_new(0x20);
          *(void **)(unaff_EBP + -0x20) = pvVar3;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar3 == (void *)0x0) {
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          }
          else {
            uVar4 = FUN_0047d01e(0x40);
            *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,
                               *(int *)(unaff_EBP + -0x18) + 2,0);
          if (iVar2 != 0) goto LAB_00478a6a;
          *(undefined4 *)(unaff_EBP + -0x14) = 0;
          iVar2 = *(int *)(extraout_ECX + 0x10);
          if (0 < iVar2) {
            *(undefined4 *)(unaff_EBP + -0x20) = 0;
            do {
              *(undefined4 *)(unaff_EBP + -0x10) = 0;
              if (0 < iVar2) {
                do {
                  piVar5 = (int *)FUN_0047c7b7(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + -0x10))
                  ;
                  puVar7 = (undefined1 *)(*(int *)(unaff_EBP + -0x14) * 8 + *piVar5);
                  piVar5 = (int *)FUN_0047c7b7(unaff_EBP + -0x34,*(undefined4 *)(unaff_EBP + -0x10))
                  ;
                  uVar1 = *puVar7;
                  puVar6 = (undefined1 *)(*piVar5 + *(int *)(unaff_EBP + -0x20));
                  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
                  *puVar6 = uVar1;
                  puVar6[1] = puVar7[1];
                  *(ushort *)(puVar6 + 2) = (ushort)(byte)puVar7[2];
                  *(ushort *)(puVar6 + 4) = (ushort)(byte)puVar7[3];
                  *(ushort *)(puVar6 + 6) = (ushort)(byte)puVar7[4];
                  *(ushort *)(puVar6 + 8) = (ushort)(byte)puVar7[5];
                  *(ushort *)(puVar6 + 10) = (ushort)(byte)puVar7[6];
                  *(ushort *)(puVar6 + 0xc) = (ushort)(byte)puVar7[7];
                } while (*(int *)(unaff_EBP + -0x10) < *(int *)(extraout_ECX + 0x10));
                iVar8 = *(int *)(unaff_EBP + -0x24);
              }
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
              iVar2 = *(int *)(extraout_ECX + 0x10);
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0xe;
            } while (*(int *)(unaff_EBP + -0x14) < iVar2);
          }
          if (*(int *)(unaff_EBP + -0x1c) != 0) {
            FUN_00431242();
            FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x1c));
          }
        }
        else {
          iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,
                               *(int *)(unaff_EBP + -0x18) + 0xb,0);
          if ((iVar2 != 0) ||
             (iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,
                                   *(int *)(unaff_EBP + -0x18) + 0xc,0), iVar2 != 0))
          goto LAB_00478a6a;
        }
        iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,
                             *(int *)(unaff_EBP + -0x18) + 3,&LAB_00478aac);
        if ((iVar2 != 0) ||
           ((0x23 < *(int *)(unaff_EBP + 0xc) &&
            (iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,
                                  *(int *)(unaff_EBP + -0x18) + 8,0), iVar2 != 0))))
        goto LAB_00478a6a;
      }
      else {
        FUN_00431380(0);
        FUN_00431380(0);
        FUN_00431380(0);
      }
      FUN_00478a7b();
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 100;
      iVar8 = iVar8 + 4;
      *(int *)(unaff_EBP + -0x24) = iVar8;
    } while (*(int *)(unaff_EBP + -0x18) < 0x65);
    if (*(int *)(unaff_EBP + 0xc) < 0x11) {
      FUN_0047b6ce(0);
    }
    else {
      iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,6,0);
      if ((iVar2 != 0) ||
         (iVar2 = FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,7,0), iVar2 != 0))
      goto LAB_00478a6a;
    }
    if (0x25 < *(int *)(unaff_EBP + 0xc)) {
      FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,9,0);
    }
    if (*(int *)(unaff_EBP + 0xc) < 0x35) {
      FUN_004776fd();
    }
    else {
      FUN_004310b4(*(undefined4 *)(unaff_EBP + 8),0x41727279,10,0);
    }
    FUN_00478ac2();
    iVar2 = 0;
  }
LAB_00478a6a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

