
void FUN_00480fc3(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  char *pcVar4;
  
  if (((byte)((ushort)*(undefined2 *)(param_1 + 2) >> 0xd) & 1) == 1) {
    FUN_0046f847(s__Using_Inventory_of_object_in_Te_006c5b74,0xffffffff);
  }
  FUN_0046fa24(0x28);
  bVar1 = *param_1;
  if (bVar1 == 0) {
    pcVar4 = s_Add_token_of_type_006c5a80;
LAB_00481045:
    FUN_0046f847(pcVar4,0xffffffff);
  }
  else {
    if (bVar1 == 1) {
      pcVar4 = s_Remove_token_of_type_006c5a94;
      goto LAB_00481045;
    }
    if (bVar1 == 2) {
      pcVar4 = s_Remove_token_at_index_006c5aac;
      goto LAB_00481045;
    }
    if (bVar1 == 3) {
      pcVar4 = s_Find_token_of_type_006c5ac4;
      goto LAB_00481045;
    }
    if (bVar1 == 4) {
      pcVar4 = s_Set_to_next_token_of_type_006c5ad8;
      goto LAB_00481045;
    }
    if (bVar1 == 5) {
      pcVar4 = s_Add_Downtown_Date_Token_of_Neigh_006c5af4;
      goto LAB_00481045;
    }
    if (bVar1 == 6) {
      pcVar4 = s_Add_Back_Home_Date_Token_of_Neig_006c5b34;
      goto LAB_00481045;
    }
  }
  bVar1 = *param_1;
  if ((bVar1 < 2) || ((2 < bVar1 && (bVar1 < 5)))) {
    switch(param_1[1]) {
    case 0:
      pcVar4 = (char *)0x6c5a78;
      break;
    case 1:
    case 3:
      pcVar4 = s_DATE_006c5a5c;
      break;
    case 2:
      pcVar4 = s_SIMDATA_006c5a50;
      break;
    case 4:
      pcVar4 = s_PURCHASE_006c5a44;
      break;
    case 5:
      pcVar4 = s_SOUVENIR_006c5a38;
      break;
    case 6:
      pcVar4 = s_SKILL_006c5a30;
      break;
    case 7:
      pcVar4 = s_MAGIC_006c5a70;
      break;
    case 8:
      pcVar4 = s_INGREDIENT_006c5a64;
      break;
    default:
      goto LAB_004810b7;
    }
    FUN_0046f847(pcVar4,0xffffffff);
LAB_004810b7:
    if ((param_1[2] & 1) == 1) {
      FUN_0046f847(s_with_object_006c5a20,0xffffffff);
      if (*(int *)(param_1 + 4) == 0) {
        FUN_0046f847(s_from_Stack_Object_s_GUID_006c5a04,0xffffffff);
      }
      else {
        FUN_0048026d(*(int *)(param_1 + 4),param_3);
      }
      FUN_0046fa24(0x20);
    }
  }
  if (*param_1 != 2) {
    if (*param_1 != 4) goto LAB_00481180;
    FUN_0046f847(s_starting_at_index_006c59e0,0xffffffff);
  }
  if ((char)param_1[2] < '\0') {
    FUN_0046f847(s_stored_in_Temp_006c59f4,0xffffffff);
    uVar2 = *(ushort *)(param_1 + 2) & 0x300;
    if ((*(ushort *)(param_1 + 2) & 0x300) == 0) {
      iVar3 = 0;
    }
    else if (uVar2 == 0x100) {
      iVar3 = 1;
    }
    else if (uVar2 == 0x200) {
      iVar3 = 2;
    }
    else {
      iVar3 = ((uVar2 == 0x300) - 1 & 0xfffffffc) + 3;
    }
    FUN_0046fa6f(iVar3,1);
    FUN_0046fa24(0x20);
  }
  else {
    FUN_0046f847(&DAT_006c59dc,0xffffffff);
  }
LAB_00481180:
  if (*param_1 < 3) {
    FUN_0046f847(s_of_count_006c59a0,0xffffffff);
    if ((param_1[2] >> 1 & 1) == 1) {
      FUN_0046f847(s_stored_in_Temp_006c59f4,0xffffffff);
      bVar1 = param_1[2] & 0xc;
      if ((param_1[2] & 0xc) == 0) {
        iVar3 = 0;
      }
      else if (bVar1 == 4) {
        iVar3 = 1;
      }
      else if (bVar1 == 8) {
        iVar3 = 2;
      }
      else {
        iVar3 = ((bVar1 == 0xc) - 1 & 0xfffffffc) + 3;
      }
      FUN_0046fa6f(iVar3,1);
      FUN_0046fa24(0x2e);
    }
    else {
      FUN_0046f847(&DAT_006c599c,0xffffffff);
    }
  }
  else if (*param_1 < 5) {
    FUN_0046f847(s___Returning_count_to_Temp_006c59c0,0xffffffff);
    bVar1 = param_1[2] & 0x60;
    if ((param_1[2] & 0x60) == 0) {
      iVar3 = 0;
    }
    else if (bVar1 == 0x20) {
      iVar3 = 1;
    }
    else if (bVar1 == 0x40) {
      iVar3 = 2;
    }
    else {
      iVar3 = ((bVar1 == 0x60) - 1 & 0xfffffffc) + 3;
    }
    FUN_0046fa6f(iVar3,1);
    FUN_0046fa24(0x20);
    FUN_0046f847(s_and_index_to_Temp_006c59ac,0xffffffff);
    uVar2 = *(ushort *)(param_1 + 2) & 0x1800;
    if ((*(ushort *)(param_1 + 2) & 0x1800) == 0) {
      iVar3 = 0;
    }
    else if (uVar2 == 0x800) {
      iVar3 = 1;
    }
    else if (uVar2 == 0x1000) {
      iVar3 = 2;
    }
    else {
      iVar3 = ((uVar2 == 0x1800) - 1 & 0xfffffffc) + 3;
    }
    FUN_0046fa6f(iVar3,1);
  }
  FUN_0046fa24(0x29);
  return;
}

