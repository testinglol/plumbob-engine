
void FUN_004aa3e7(void)

{
  short sVar1;
  short *psVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int extraout_ECX;
  undefined1 extraout_var;
  int unaff_EBP;
  float10 fVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_6c;
  
  FUN_00634c24();
  psVar2 = *(short **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x54) = (int)*psVar2;
  *(int *)(unaff_EBP + -0x4c) = (int)psVar2[2];
  sVar1 = psVar2[3];
  *(int *)(unaff_EBP + -0x58) = (int)psVar2[1];
  *(int *)(unaff_EBP + -0x50) = (int)sVar1;
  piVar3 = *(int **)(extraout_ECX + 0x1cc);
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x58);
  piVar6 = *(int **)(extraout_ECX + 0x1c8);
  *(int **)(unaff_EBP + -0x34) = piVar3;
  *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x54);
  *(undefined4 *)(unaff_EBP + -0x60) = *(undefined4 *)(unaff_EBP + -0x50);
  *(int **)(unaff_EBP + -0x28) = piVar6;
  *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x4c);
  if (piVar6 == piVar3) {
LAB_004aa7eb:
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  do {
    piVar6 = (int *)*piVar6;
    *(undefined4 *)(unaff_EBP + -0x40) = 0;
    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
    iVar8 = piVar6[0x3d];
    cVar5 = *(char *)(extraout_ECX + 0x50);
    *(int *)(unaff_EBP + -0x40) = iVar8;
    iVar4 = piVar6[0x3e];
    *(int *)(unaff_EBP + -0x3c) = iVar4;
    *(int *)(unaff_EBP + -0x1c) = piVar6[0x44];
    if (cVar5 == '\0') {
LAB_004aa4ab:
      if (*(short *)(piVar6[0x46] + 0x12) == 2) {
        local_6c = 0.0;
        iVar8 = FUN_006359f2(piVar6,0,&cXObject::RTTI_Type_Descriptor,
                             &cXPerson::RTTI_Type_Descriptor);
      }
      else {
        iVar8 = 0;
      }
      if ((*(int *)(unaff_EBP + -0x1c) <= *(int *)(extraout_ECX + 0x18)) ||
         (((iVar8 != 0 && (*(int *)(unaff_EBP + -0x1c) == *(int *)(extraout_ECX + 0x18) + 1)) &&
          (*(short *)(iVar8 + 0x5dc) != 0)))) {
        local_6c = 1.4013e-45;
        local_6c = (float)FUN_00433116(unaff_EBP + -0x40);
        cVar5 = FUN_00433136();
        if (cVar5 == '\0') {
          *(char *)(unaff_EBP + -0x18) = (char)(*(int *)(unaff_EBP + -0x3c) >> 4);
          *(char *)(unaff_EBP + -0x17) = (char)(*(int *)(unaff_EBP + -0x40) >> 4);
          *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(unaff_EBP + -0x1c);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x3c);
          iVar8 = DAT_006e54d8;
          *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x40);
          local_6c = *(float *)(iVar8 + 0x84);
          FUN_00434ffd();
          local_6c = 1.43493e-42;
          FUN_0047bd91(unaff_EBP + -0x44,unaff_EBP + -0x48,*(undefined4 *)(DAT_006e54d8 + 0x84));
          *(undefined4 **)(unaff_EBP + -0x38) = &local_6c;
          local_6c = (float)CONCAT13(extraout_var,
                                     CONCAT12(*(undefined1 *)(unaff_EBP + -0x16),
                                              CONCAT11(*(undefined1 *)(unaff_EBP + -0x17),
                                                       *(undefined1 *)(unaff_EBP + -0x18))));
          FUN_004796d9(unaff_EBP + -0x30);
          *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + -0x2f);
          local_6c = (float)(unaff_EBP + -0x18);
          FUN_004b3e97(unaff_EBP + -0x2c,unaff_EBP + -0x24);
          *(int *)(unaff_EBP + -0x24) =
               *(int *)(unaff_EBP + -0x24) -
               ((uint)*(byte *)(unaff_EBP + -0xe) << ((char)DAT_006f0088 + 1U & 0x1f));
          psVar2 = *(short **)(unaff_EBP + 8);
          if (((psVar2[1] + -200 <= *(int *)(unaff_EBP + -0x2c)) &&
              (*(int *)(unaff_EBP + -0x2c) <= psVar2[3] + 200)) &&
             ((*psVar2 + -600 <= *(int *)(unaff_EBP + -0x24) &&
              (*(int *)(unaff_EBP + -0x24) <= psVar2[2] + 600)))) {
            local_6c = *(float *)(unaff_EBP + -0x1c);
            fVar9 = (float10)FUN_0046755a(unaff_EBP + -0x48);
            local_6c = (float)fVar9;
            FUN_004b4722();
            local_6c = -NAN;
            uVar12 = *(undefined4 *)(unaff_EBP + 0xc);
            iVar8 = unaff_EBP + -0x40;
            uVar11 = *(undefined4 *)(unaff_EBP + -0x1c);
            FUN_004b469d(iVar8,uVar11,uVar12);
            FUN_004b97eb(iVar8,uVar11,uVar12);
            local_6c = 1.4013e-45;
            FUN_0043908c();
            *(undefined1 *)(unaff_EBP + -0xe) = 0;
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
            if (*(char *)(extraout_ECX + 0x48) == '\0') {
              if (*(char *)(extraout_ECX + 0x49) != '\0') {
                cVar5 = *(char *)(unaff_EBP + -0x17);
                local_6c = 6.855544e-39;
                uVar10 = __allshl();
                if ((*(uint *)(extraout_ECX + 0x208 + cVar5 * 8) & (uint)uVar10) != 0 ||
                    (*(uint *)(extraout_ECX + 0x20c + cVar5 * 8) & (uint)((ulonglong)uVar10 >> 0x20)
                    ) != 0) goto LAB_004aa692;
              }
            }
            else {
LAB_004aa692:
              local_6c = 6.855603e-39;
              cVar5 = FUN_004cebce();
              if ((cVar5 == '\0') && ((*(ushort *)((int)piVar6 + 0x5a) & 0x400) != 0)) {
                *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -0x1f) = *(undefined1 *)(unaff_EBP + -0x17);
                *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(unaff_EBP + -0x16);
                cVar5 = *(char *)(extraout_ECX + 0x48);
                *(undefined1 *)(unaff_EBP + -4) = 1;
                if (cVar5 == '\0') {
                  local_6c = 6.855685e-39;
                  iVar8 = FUN_00435968();
                  if (*(int *)(&DAT_006f4620 + (*(int *)(DAT_006e54d8 + 0x84) * 0x40 + iVar8) * 4)
                      != 0) {
                    local_6c = (float)(unaff_EBP + -0x20);
                    FUN_0053c0e0(*(int *)(&DAT_006f4620 +
                                         (*(int *)(DAT_006e54d8 + 0x84) * 0x40 + iVar8) * 4));
                  }
                }
                if (*(int *)(extraout_ECX + 0x18) == piVar6[0x44]) {
                  if (*(char *)(extraout_ECX + 0x48) == '\0') {
                    cVar5 = *(char *)(unaff_EBP + -0x1f);
                    local_6c = 6.85579e-39;
                    uVar10 = __allshl();
                    if ((*(uint *)(extraout_ECX + 0x208 + cVar5 * 8) & (uint)uVar10) == 0 &&
                        (*(uint *)(extraout_ECX + 0x20c + cVar5 * 8) &
                        (uint)((ulonglong)uVar10 >> 0x20)) == 0) goto LAB_004aa758;
                  }
                  sVar1 = *(short *)((int)piVar6 + 0x8e);
                  *(undefined1 *)(unaff_EBP + -0xd) = 1;
                  *(bool *)(unaff_EBP + -0xe) = sVar1 != 0;
                  *(undefined2 *)((int)piVar6 + 0x8e) = 1;
                }
LAB_004aa758:
                *(undefined1 *)(unaff_EBP + -4) = 0;
              }
            }
            local_6c = *(float *)(unaff_EBP + 0xc);
            (**(code **)(*piVar6 + 0x30))(unaff_EBP + -0x58);
            iVar4 = DAT_006f0084;
            iVar8 = DAT_006f0080;
            if ((*(int *)(unaff_EBP + -0x58) < *(int *)(unaff_EBP + -0x50)) &&
               (*(int *)(unaff_EBP + -0x54) < *(int *)(unaff_EBP + -0x4c))) {
              *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x58) + DAT_006f0080;
              *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) + iVar8;
              *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x54) + iVar4;
              *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) + iVar4;
              local_6c = 6.855954e-39;
              FUN_004a7901();
              if ((*(int *)(unaff_EBP + -0x58) < *(int *)(unaff_EBP + -0x50)) &&
                 (((*(int *)(unaff_EBP + -0x54) < *(int *)(unaff_EBP + -0x4c) &&
                   (*(int *)(extraout_ECX + 0x68) != 0)) && (DAT_006e4870 == '\0')))) {
                local_6c = (float)(unaff_EBP + -0x58);
                FUN_005cf0fa();
              }
            }
            if (*(char *)(unaff_EBP + -0xd) != '\0') {
              *(ushort *)((int)piVar6 + 0x8e) = (ushort)*(byte *)(unaff_EBP + -0xe);
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
      }
    }
    else {
      if (DAT_006e4a84 == 0) {
        uVar7 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x34) + 0xc) +
                                          (char)(iVar4 >> 4) * 4) + (int)(char)(iVar8 >> 4)) & 0x20)
                >> 5;
      }
      else {
        uVar7 = 1;
      }
      if (uVar7 != 0) goto LAB_004aa4ab;
    }
    *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 4;
    if (*(int *)(unaff_EBP + -0x28) == *(int *)(unaff_EBP + -0x34)) goto LAB_004aa7eb;
    piVar6 = *(int **)(unaff_EBP + -0x28);
  } while( true );
}

