
void FUN_00458992(void)

{
  undefined2 uVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  byte bVar7;
  uint uVar8;
  int unaff_EBP;
  int iVar9;
  int iVar10;
  
  FUN_00634c24();
  if (((*(short *)(*(int *)(extraout_ECX[1] + 0x118) + 0x12) != 7) ||
      (((uint)(int)*(short *)(*extraout_ECX + 0x60e) >> 1 & 1) != 0)) ||
     (((uint)(int)*(short *)(*extraout_ECX + 0x60e) >> 2 & 1) != 0)) {
    iVar5 = FUN_00457e1c();
    *(int *)(unaff_EBP + -0x24) = iVar5;
    if ((iVar5 != 0) && (DAT_006e50e4 == '\0')) {
      iVar10 = *extraout_ECX;
      iVar9 = *(int *)(iVar5 + 4);
      sVar4 = *(short *)(iVar10 + 0x600);
      *(bool *)(unaff_EBP + -0xe) = *(short *)(iVar10 + 0x5cc) != 0;
      if ((sVar4 == 0) || (0x11 < sVar4)) {
        *(undefined1 *)(unaff_EBP + -0xf) = 0;
      }
      else {
        *(undefined1 *)(unaff_EBP + -0xf) = 1;
      }
      uVar8 = (uint)(int)*(short *)(iVar10 + 0x60e) >> 1;
      bVar7 = (byte)uVar8 & 1;
      sVar4 = *(short *)(iVar10 + 0x5d0);
      uVar1 = *(undefined2 *)(iVar10 + 0x5d4);
      *(byte *)(unaff_EBP + -0xd) = (byte)((uint)(int)*(short *)(iVar10 + 0x60e) >> 2) & 1;
      *(undefined2 *)(unaff_EBP + -0x18) = uVar1;
      *(bool *)(unaff_EBP + -0x10) = sVar4 != 0;
      iVar9 = iVar9 + -1;
      *(int *)(unaff_EBP + -0x14) = iVar9;
      if (-1 < iVar9) {
        do {
          if ((iVar9 < 0) || (*(int *)(iVar5 + 4) <= iVar9)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(*(int *)(iVar5 + 0x10) + iVar9 * 4);
          }
          if (0 < *(short *)(iVar5 + 0x1c)) {
            cVar2 = FUN_00407525();
            if ((cVar2 == '\x01') &&
               ((*(short *)(extraout_ECX[1] + 0xc0) == 4 ||
                (*(short *)(extraout_ECX[1] + 0xc0) == 7)))) {
              uVar6 = FUN_0042a8e3(CONCAT22((short)((uint)*extraout_ECX >> 0x10),
                                            *(undefined2 *)(*extraout_ECX + 0x5ca)));
              *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
              iVar10 = unaff_EBP + -0x1a;
              uVar6 = FUN_0043e2ff(iVar10);
              sVar4 = FUN_0041f662(0,uVar6,iVar10);
              if (((sVar4 == 0) ||
                  (((uVar8 & 1) != 0 && ((*(uint *)(iVar5 + 0x14) >> 10 & 1) == 0)))) ||
                 ((*(char *)(unaff_EBP + -0xd) != '\0' && ((*(uint *)(iVar5 + 0x14) >> 9 & 1) == 0))
                 )) goto LAB_00458c4d;
              uVar6 = FUN_0041f010(*extraout_ECX,extraout_ECX[1],*(undefined4 *)(iVar5 + 0x18),0);
              *(undefined4 *)(unaff_EBP + -4) = 0;
              FUN_00458cd7(uVar6);
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            }
            else {
              if ((((uVar8 & 1) != 0) && ((*(uint *)(iVar5 + 0x14) >> 10 & 1) == 0)) ||
                 ((*(char *)(unaff_EBP + -0xd) != '\0' && ((*(uint *)(iVar5 + 0x14) >> 9 & 1) == 0))
                 )) goto LAB_00458c4d;
              if (*(char *)(unaff_EBP + -0xf) == '\0') {
                if (((uVar8 & 1) == 0) && (*(byte *)(unaff_EBP + -0xd) == bVar7)) {
                  bVar3 = (byte)(*(uint *)(iVar5 + 0x14) >> 6);
                  goto LAB_00458b98;
                }
              }
              else {
                bVar3 = (byte)(*(uint *)(iVar5 + 0x14) >> 4);
LAB_00458b98:
                if ((~bVar3 & 1) == 0) goto LAB_00458c4d;
              }
              if ((((*(short *)(unaff_EBP + -0x18) < *(short *)(iVar5 + 0x1c)) ||
                   ((*(uint *)(iVar5 + 0x14) >> 7 & 1) != 0)) ||
                  (((cVar2 = FUN_004074bc(), cVar2 != '\0' ||
                    ((*(uint *)(iVar5 + 0x14) >> 5 & 1) == 0)) &&
                   ((*(char *)(unaff_EBP + -0xe) != '\0' && ((*(byte *)(iVar5 + 0x14) & 1) == 0)))))
                  ) || ((cVar2 = FUN_004074bc(), cVar2 == '\x01' &&
                        ((*(char *)(unaff_EBP + -0xe) != '\0' &&
                         (((((uVar8 & 1) != 0 || (*(byte *)(unaff_EBP + -0xd) != bVar7)) &&
                           (*(char *)(unaff_EBP + -0x10) == '\0')) &&
                          (*(short *)(extraout_ECX[1] + 0x84) != 0)))))))) goto LAB_00458c4d;
              uVar6 = FUN_0041f010(*extraout_ECX,extraout_ECX[1],*(undefined4 *)(iVar5 + 0x18),0);
              *(undefined4 *)(unaff_EBP + -4) = 1;
              FUN_00458cd7(uVar6);
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            }
            FUN_005b8770();
          }
LAB_00458c4d:
          iVar9 = *(int *)(unaff_EBP + -0x14) + -1;
          *(int *)(unaff_EBP + -0x14) = iVar9;
          if (iVar9 < 0) break;
          iVar5 = *(int *)(unaff_EBP + -0x24);
        } while( true );
      }
      if (*(short *)(*(int *)(extraout_ECX[1] + 0x118) + 0x12) == 2) {
        uVar6 = FUN_006359f2(extraout_ECX[1],0,&cXObject::RTTI_Type_Descriptor,
                             &cXPerson::RTTI_Type_Descriptor,0);
        iVar5 = FUN_0041f101();
        if ((iVar5 != 0) && ((*(uint *)(iVar5 + 0x14) >> 1 & 1) != 0)) {
          FUN_0041ee9b(*extraout_ECX,uVar6);
          *(undefined4 *)(unaff_EBP + -4) = 2;
          FUN_00458cd7(unaff_EBP + -0x68);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

