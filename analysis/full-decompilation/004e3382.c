
void FUN_004e3382(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBP;
  char *pcVar5;
  
  FUN_00634c24();
  iVar2 = FUN_00635845(PTR_s_FamHarness_txt_006c99b0,&DAT_006c0a78);
  if (iVar2 != 0) {
    FUN_006357d8(iVar2,&DAT_006c08e0,s_Here_we_go_006c9ad0);
    FUN_0063558d(iVar2);
  }
  FUN_0046f824(unaff_EBP + -0x898,0,0x100);
  *(undefined ***)(unaff_EBP + -0x8a4) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x144,0,0x100);
  *(undefined ***)(unaff_EBP + -0x150) = &PTR_FUN_00666524;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0055e4e2(unaff_EBP + -0x25);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0055e4e2(unaff_EBP + -0x35);
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  do {
    if (iVar2 < 1) {
      FUN_004e334f(s_All_done_006c99c4);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004b503e();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004b503e();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    FUN_0046f824(unaff_EBP + -0x680,0,0x100);
    *(undefined ***)(unaff_EBP + -0x68c) = &PTR_FUN_00666524;
    FUN_0046f847(s_Op_count_006c9ac4,0xffffffff);
    FUN_0046f8e4(unaff_EBP + -0x68c);
    FUN_0046fa40(*(undefined4 *)(unaff_EBP + 8));
    FUN_0046f847(&DAT_006c08dc,0xffffffff);
    FUN_004e334f(*(undefined4 *)(unaff_EBP + -0x14c));
    FUN_004071be(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30));
    FUN_004e1a40(unaff_EBP + -0x34);
    iVar2 = *(int *)(unaff_EBP + -0x30);
    iVar3 = iVar2 - *(int *)(unaff_EBP + -0x34) >> 2;
    if (iVar3 == 0) {
LAB_004e35ca:
      iVar2 = FUN_004e1ac7();
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + -1;
      *(int *)(unaff_EBP + -0x10) = iVar2;
      if (iVar2 == -1) {
        pcVar5 = s_MakeNewFamily_failed_006c9a9c;
LAB_004e38b3:
        FUN_004e334f(pcVar5);
      }
      else {
        FUN_0046f824(unaff_EBP + -0x78c,0,0x100);
        *(undefined ***)(unaff_EBP + -0x798) = &PTR_FUN_00666524;
        FUN_0046f847(s_Made_family_006c9a8c,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x798);
        FUN_0046fa40(*(undefined4 *)(unaff_EBP + -0x10));
        FUN_0046f847(&DAT_006c08dc,0xffffffff);
        FUN_004e334f(*(undefined4 *)(unaff_EBP + -0x14c));
        FUN_0046f824(unaff_EBP + -0x250,0,0x100);
        *(undefined ***)(unaff_EBP + -0x25c) = &PTR_FUN_00666524;
        FUN_0046f847(s_Test_family_006c9a7c,0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x25c);
        FUN_0046fa40(*(undefined4 *)(unaff_EBP + -0x10));
        FUN_005d4bbf(*(undefined4 *)(unaff_EBP + -0x14c));
        cVar1 = FUN_004e1d27(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x44);
        if (cVar1 == '\0') {
          FUN_004e334f(s_SetFamilyName_failed_006c9a64);
        }
        iVar3 = FUN_004e3901(7);
        iVar2 = iVar3 + 1;
        *(int *)(unaff_EBP + -0x18) = iVar3;
        while (0 < iVar2) {
          iVar2 = FUN_004e1df3();
          *(int *)(unaff_EBP + -0x14) = iVar2;
          if (iVar2 == -1) {
            pcVar5 = s_MakeNewPerson_failed_006c99d0;
            goto LAB_004e38b3;
          }
          FUN_0046f824(unaff_EBP + -0x35c,0,0x100);
          *(undefined ***)(unaff_EBP + -0x368) = &PTR_FUN_00666524;
          FUN_0046f847(s_Made_person_006c9a54,0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x368);
          FUN_0046fa40(*(undefined4 *)(unaff_EBP + -0x14));
          FUN_0046f847(&DAT_006c08dc,0xffffffff);
          FUN_004e334f(*(undefined4 *)(unaff_EBP + -0x14c));
          FUN_004e3982(*(undefined4 *)(unaff_EBP + -0x14));
          cVar1 = FUN_004e1e77(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x14)
                              );
          if (cVar1 == '\0') {
            FUN_004e334f(s_AddFamilyMember_failed_006c9a3c);
          }
          FUN_004e1978(*(undefined4 *)(unaff_EBP + -0x10));
          FUN_004071be(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
          FUN_004e1d96(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x24);
          uVar4 = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24);
          if ((uVar4 & 0xfffffffc) != 0) {
            iVar2 = FUN_004e3901((int)uVar4 >> 2);
            *(undefined4 *)(unaff_EBP + -0x14) =
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + iVar2 * 4);
            iVar2 = FUN_004e3901(5);
            if (iVar2 == 0) {
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + -1;
              FUN_004e3982(*(undefined4 *)(unaff_EBP + -0x14));
              FUN_0046f824(unaff_EBP + -0x574,0,0x100);
              *(undefined ***)(unaff_EBP + -0x580) = &PTR_FUN_00666524;
              FUN_0046f847(s_Edited_person_006c99e8,0xffffffff);
              iVar2 = unaff_EBP + -0x580;
LAB_004e386a:
              FUN_0046f8e4(iVar2);
              FUN_0046fa40(*(undefined4 *)(unaff_EBP + -0x14));
              FUN_0046f847(&DAT_006c08dc,0xffffffff);
              pcVar5 = *(char **)(unaff_EBP + -0x14c);
LAB_004e3898:
              FUN_004e334f(pcVar5);
            }
            else if (iVar2 == 1) {
              *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + -1;
              cVar1 = FUN_004e1ebe(*(undefined4 *)(unaff_EBP + -0x10),
                                   *(undefined4 *)(unaff_EBP + -0x14));
              if (cVar1 == '\0') {
                pcVar5 = s_RemoveFamilyMember_failed_006c9a20;
                goto LAB_004e3898;
              }
              cVar1 = FUN_004e1e40(*(undefined4 *)(unaff_EBP + -0x14));
              if (cVar1 != '\0') {
                FUN_004de70b(s_Deleted_person_006c99f8,0xffffffff);
                iVar2 = unaff_EBP + -0x9b0;
                goto LAB_004e386a;
              }
              FUN_004e334f(s_DeletePerson_failed_006c9a08);
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -1;
            }
          }
          iVar2 = *(int *)(unaff_EBP + -0x18);
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -1;
        }
      }
    }
    else {
      if (iVar3 != 0x20) {
        iVar2 = FUN_004e3901(0x20 - iVar3);
        if (iVar2 != 0) goto LAB_004e35ca;
        iVar2 = *(int *)(unaff_EBP + -0x30);
      }
      iVar2 = FUN_004e3901(iVar2 - *(int *)(unaff_EBP + -0x34) >> 2);
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x34) + iVar2 * 4);
      FUN_004071be(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
      FUN_004e1d96(*(undefined4 *)(unaff_EBP + -0x18),unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24) >> 2 != 0) {
        do {
          FUN_004e1e40(*(undefined4 *)
                        (*(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x10) * 4));
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(uint *)(unaff_EBP + -0x10) <
                 (uint)(*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24) >> 2));
      }
      FUN_004e1ae3(*(undefined4 *)(*(int *)(unaff_EBP + -0x34) + *(int *)(unaff_EBP + -0x10) * 4));
      FUN_0046f824(unaff_EBP + -0x468,0,0x100);
      *(undefined ***)(unaff_EBP + -0x474) = &PTR_FUN_00666524;
      FUN_0046f847(s_Removed_family_006c9ab4,0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0x474);
      FUN_0046fa40(*(undefined4 *)(unaff_EBP + -0x18));
      FUN_0046f847(&DAT_006c08dc,0xffffffff);
      FUN_004e334f(*(undefined4 *)(unaff_EBP + -0x14c));
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + -1;
    }
    iVar2 = *(int *)(unaff_EBP + 8);
  } while( true );
}

