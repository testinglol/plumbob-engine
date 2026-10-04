
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0047fca8(void)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  size_t sVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  byte bVar9;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  uint uVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar5 = *(undefined4 *)(unaff_EBP + 0x10);
  FUN_0046fa24(0x28);
  iVar1 = *(int *)(unaff_EBP + 8);
  puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
  switch(*(byte *)(iVar1 + 5) & 0x7f) {
  case 0:
    pcVar3 = s_message__006c56e0;
    break;
  case 1:
    pcVar3 = s_choice__006c56d4;
    break;
  case 2:
    uVar8 = CONCAT31((int3)((uint)extraout_ECX >> 8),*(byte *)(iVar1 + 7) >> 4) & 0xffffff07;
    FUN_0047e457(puVar2[3],8,CONCAT22((short)(uVar8 >> 0x10),(ushort)(byte)uVar8),uVar5,
                 *(undefined4 *)(unaff_EBP + 0x14));
    FUN_0046f847(&DAT_006c53d8,0xffffffff);
    pcVar3 = s_tri_choice__006c5618;
    break;
  case 3:
    pcVar3 = s_text_entry__006c56ec;
    break;
  case 4:
    pcVar3 = s_tutorial__006c56fc;
    break;
  case 5:
    pcVar3 = s_Temp_0_____Get_Downtown_Lot__006c56b4;
    goto code_r0x0047fd3b;
  default:
    goto LAB_0047fd95;
  case 7:
    pcVar3 = s_Temp_0_____Get_Vacation_Lot__006c5694;
    goto code_r0x0047fd3b;
  case 10:
    pcVar3 = s_PhoneBook__Temp_0____Get_Neighbo_006c5628;
    goto code_r0x0047fd3b;
  case 0xb:
    pcVar3 = s_Temp_0_____Get_Studiotown_Lot__006c5674;
    goto code_r0x0047fd3b;
  case 0xc:
    pcVar3 = s_SpellBook__Me_<__person_to_open__006c55f4;
    break;
  case 0xd:
    pcVar3 = s_Temp_0_____Get_Magicland_Lot__006c5654;
code_r0x0047fd3b:
    FUN_0046f847(pcVar3,0xffffffff);
    goto code_r0x0047ff64;
  case 0xf:
    pcVar3 = s_CookBook__Me_<__person_to_open__006c55d4;
  }
  FUN_0046f847(pcVar3,0xffffffff);
LAB_0047fd95:
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
  uVar5 = *puVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00470383(uVar5,0x12d,0);
  pcVar3 = (char *)FUN_004705f2(*(undefined1 *)(iVar1 + 2),0xffffffff);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = s_string_error_006c55c4;
  }
  FUN_0046f824(unaff_EBP + -0x178,0,0x100);
  *(undefined ***)(unaff_EBP + -0x184) = &PTR_FUN_00666524;
  FUN_0046f847(pcVar3,0x30);
  sVar4 = _strlen(pcVar3);
  if (0x30 < sVar4) {
    FUN_0046f847(&DAT_006c220c,0xffffffff);
  }
  FUN_0046f917(unaff_EBP + -0x184,0xffffffff);
  if ((byte)((*(byte *)(iVar1 + 7) >> 6 & 2) + (*(byte *)(iVar1 + 7) & 1)) != '\0') {
    uVar5 = FUN_0046f847(&DAT_006c25a8,0xffffffff);
    uVar8 = CONCAT31((int3)((uint)uVar5 >> 8),*(byte *)(iVar1 + 7)) & 0xffffff01;
    uVar10 = CONCAT31((int3)((uint)extraout_ECX_00 >> 8),*(byte *)(iVar1 + 7) >> 6) & 0xffffff02;
    FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xed,
                 CONCAT22((short)(uVar10 >> 0x10),(ushort)(byte)uVar10) + 1 +
                 CONCAT22((short)(uVar8 >> 0x10),(ushort)(byte)uVar8));
    FUN_0046f917(&DAT_006e54e8,0xffffffff);
  }
  if ((*(byte *)(iVar1 + 7) & 0xe) != 2) {
    uVar5 = FUN_0046f847(s___icon__006c55b8,0xffffffff);
    bVar9 = *(byte *)(iVar1 + 7) & 0xe;
    if (bVar9 == 8) {
      iVar6 = FUN_004705f2(*(undefined1 *)(iVar1 + 1),0xffffffff);
      uVar5 = 0xffffffff;
      if (iVar6 == 0) {
        FUN_0046f847(s_name_006c4188,0xffffffff);
        uVar8 = (uint)*(byte *)(iVar1 + 1);
LAB_0047fefb:
        FUN_0046fa40(uVar8);
      }
      else {
        uVar7 = FUN_004705f2(*(undefined1 *)(iVar1 + 1),0xffffffff);
        FUN_0046f847(uVar7,uVar5);
      }
    }
    else {
      if (bVar9 == 6) {
        FUN_0046f847(&DAT_006c518c,0xffffffff);
        uVar8 = *(byte *)(iVar1 + 1) + 5000;
        goto LAB_0047fefb;
      }
      uVar8 = CONCAT31((int3)((uint)uVar5 >> 8),*(byte *)(iVar1 + 7) >> 1) & 0xffffff07;
      FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xf4,
                   CONCAT22((short)(uVar8 >> 0x10),(ushort)(byte)uVar8) + 1);
      FUN_0046f917(&DAT_006e54e8,0xffffffff);
    }
  }
  FUN_0046fa24(0x29);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
code_r0x0047ff64:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

