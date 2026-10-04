
void FUN_00439b54(void)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  int *piVar7;
  int *extraout_ECX;
  int unaff_EBP;
  ushort *puVar8;
  char *pcVar9;
  undefined *puVar10;
  undefined *puVar11;
  
  FUN_00634c24();
  if (((uint)extraout_ECX[0x45] >> 8 & 1) != 0) {
    sVar2 = FUN_0047471f();
    if (sVar2 == 0) {
      *(byte *)((int)extraout_ECX + 0x115) = *(byte *)((int)extraout_ECX + 0x115) & 0xfe;
    }
    else {
      *(byte *)((int)extraout_ECX + 0x115) = *(byte *)((int)extraout_ECX + 0x115) & 0xfe;
      if (DAT_006c2973 == '\0') {
        FUN_00444346(extraout_ECX);
        (**(code **)(*extraout_ECX + 0x38))(0);
      }
      else {
        FUN_0046f824(unaff_EBP + -0x3a4,0,0x100);
        *(undefined ***)(unaff_EBP + -0x3b0) = &PTR_FUN_00666524;
        FUN_0043a0ca(unaff_EBP + -0x3b0);
        FUN_0046f824(unaff_EBP + -0x188,0,0x100);
        *(undefined ***)(unaff_EBP + -0x194) = &PTR_FUN_00666524;
        FUN_0046f847(s_An_error_occurred_in_object___006c2b84,0xffffffff);
        FUN_0046f847(*(undefined4 *)(extraout_ECX[0x47] + 0x18),0xffffffff);
        FUN_0046f847(&DAT_006c2b80,0xffffffff);
        FUN_0046fa40((int)(short)extraout_ECX[0x3c]);
        FUN_0046f847(&DAT_006c2b7c,0xffffffff);
        FUN_0046f917(unaff_EBP + -0x3b0,0xffffffff);
        FUN_00632b81(1);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_0046fb9b(unaff_EBP + -0x298,0x104);
        iVar5 = DAT_006e486c;
        *(undefined ***)(unaff_EBP + -0x2a4) = &PTR_LAB_00666cdc;
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x2a0);
        uVar3 = FUN_00428886(*(undefined4 *)(*(int *)(iVar5 + 0x1c) + 0x98));
        FUN_00635858(*(undefined4 *)(unaff_EBP + -0x14),s___ObjectError_h_02d_t_d_txt_006c2b60,uVar3
                    );
        FUN_00632c55(*(undefined4 *)(unaff_EBP + -0x2a0),2,DAT_00689070);
        if (*(int *)(unaff_EBP + -0x80 + *(int *)(*(int *)(unaff_EBP + -0x88) + 4)) == 0) {
          puVar10 = &DAT_006c08dc;
          FUN_006323d0(*(undefined4 *)(unaff_EBP + -400));
          FUN_006323d0(puVar10);
          puVar11 = &DAT_006c2b5c;
          puVar10 = PTR_s_Sep_25_2003__14_23_46_006c7b6c;
          FUN_006323d0(s_Build__006c2b54);
          FUN_006323d0(puVar10);
          FUN_006323d0(puVar11);
          uVar4 = -(uint)(unaff_EBP != 0x88) & unaff_EBP - 0x7cU;
          *(uint *)(unaff_EBP + -0x18) = uVar4;
          FUN_00454524(uVar4);
          if (*(short *)(extraout_ECX[0x46] + 0x12) == 2) {
            FUN_006323d0(s_Person_Data__006c2b44);
            iVar5 = FUN_006359f2(extraout_ECX,0,&cXObject::RTTI_Type_Descriptor,
                                 &cXPerson::RTTI_Type_Descriptor,0);
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            *(int *)(unaff_EBP + -0x14) = iVar5 + 0x58c;
            do {
              puVar11 = &DAT_006c08dc;
              uVar3 = CONCAT22((short)((uint)*(undefined2 **)(unaff_EBP + -0x14) >> 0x10),
                               **(undefined2 **)(unaff_EBP + -0x14));
              puVar10 = &DAT_006c285c;
              FUN_006321fb(*(undefined4 *)(unaff_EBP + -0x10));
              FUN_006323d0(puVar10);
              FUN_006330c7(uVar3);
              FUN_006323d0(puVar11);
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 2;
            } while (*(int *)(unaff_EBP + -0x10) < 0x100);
          }
          FUN_006323d0(s_Data__006c2b3c);
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          puVar8 = (ushort *)((int)extraout_ECX + 0x4a);
          do {
            uVar4 = (uint)*puVar8;
            puVar11 = &DAT_006c08dc;
            puVar10 = &DAT_006c285c;
            FUN_006321fb(*(undefined4 *)(unaff_EBP + -0x10));
            FUN_006323d0(puVar10);
            FUN_006330c7(uVar4);
            FUN_006323d0(puVar11);
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            puVar8 = puVar8 + 1;
          } while (*(int *)(unaff_EBP + -0x10) < 0x48);
          FUN_006323d0(s_Attributes__006c2b2c);
          iVar5 = 0;
          if (0 < extraout_ECX[0xc]) {
            do {
              puVar11 = &DAT_006c08dc;
              uVar3 = CONCAT22((short)((uint)extraout_ECX[0xb] >> 0x10),
                               *(undefined2 *)(extraout_ECX[0xb] + iVar5 * 2));
              puVar10 = &DAT_006c285c;
              FUN_006321fb(iVar5);
              FUN_006323d0(puVar10);
              FUN_006330c7(uVar3);
              FUN_006323d0(puVar11);
              iVar5 = iVar5 + 1;
            } while (iVar5 < extraout_ECX[0xc]);
          }
          FUN_006323d0(s_Temps__006c2b20);
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          puVar8 = (ushort *)((int)extraout_ECX + 0x3a);
          do {
            uVar4 = (uint)*puVar8;
            puVar11 = &DAT_006c08dc;
            puVar10 = &DAT_006c285c;
            FUN_006321fb(*(undefined4 *)(unaff_EBP + -0x10));
            FUN_006323d0(puVar10);
            FUN_006330c7(uVar4);
            FUN_006323d0(puVar11);
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
            puVar8 = puVar8 + 1;
          } while (*(int *)(unaff_EBP + -0x10) < 8);
          FUN_006323d0(&DAT_006c08dc);
          FUN_0042a27e(*(undefined4 *)(unaff_EBP + -0x18));
          FUN_0046f847(s_The_stack_trace_is_saved_in___006c2b00,0xffffffff);
          FUN_0046f917(unaff_EBP + -0x2a4,0xffffffff);
          pcVar9 = &DAT_006c2afc;
        }
        else {
          pcVar9 = s_The_stack_trace_could_not_be_sav_006c2ad4;
        }
        FUN_0046f847(pcVar9,0xffffffff);
        pvVar6 = operator_new(0x148);
        *(void **)(unaff_EBP + -0x18) = pvVar6;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (pvVar6 == (void *)0x0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = (int *)FUN_00523434();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x1c))
                    (unaff_EBP + -0x10,unaff_EBP + -0x14,unaff_EBP + -0x18);
          iVar5 = FUN_005dd5e1(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14)
                               ,*(undefined4 *)(unaff_EBP + -0x18));
          piVar7[0x19] = iVar5;
          uVar3 = FUN_005d4956(s_Object_Error_006c2ac4);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_00523771(uVar3);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          FUN_005d4956(*(undefined4 *)(unaff_EBP + -400));
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_00523be3(unaff_EBP + -0x24);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          uVar3 = FUN_005d4956(s_Cancel_006c2abc);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_0052386b(uVar3,0);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          uVar3 = FUN_005d4956(s_Reset_006c2ab4);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_0052386b(uVar3,1);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          uVar3 = FUN_005d4956(s_Delete_006c2aac);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_0052386b(uVar3,2);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005b8770();
          FUN_004e609e();
          cVar1 = FUN_004e6133();
          if (cVar1 != '\0') {
            (**(code **)(*piVar7 + 0xa8))(1,0,0);
          }
          iVar5 = FUN_004f6c41(piVar7,1,0);
          if (iVar5 == 1) {
            FUN_00444346(extraout_ECX);
            (**(code **)(*extraout_ECX + 0x38))(0);
          }
          else if (iVar5 == 2) {
            FUN_0044127f((short)extraout_ECX[0x3c]);
          }
          (**(code **)(*DAT_006fe8bc + 0x18))();
          FUN_005da4c7(piVar7);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00632c42();
        FUN_00632b08();
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

