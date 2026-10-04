
void __fastcall FUN_0043c6ee(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x24);
  iVar3 = *(int *)(param_1 + 0x20);
  FUN_004ff6fa(0x61616161,s_Scanning_Sims_1_Objects_006c370c);
  iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x140))();
  if (iVar4 != 0) {
    FUN_00412825(param_1 + 0x140);
  }
  FUN_004ff6fa(0x61616161,s_Scanning_User_Objects_006c36f4);
  iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x250))();
  if (iVar4 != 0) {
    FUN_00412825(param_1 + 0x250);
  }
  FUN_004ff6fa(0x61616161,s_Scanning_UserData_People_006c36d8);
  uVar1 = *(undefined1 *)(param_1 + 0x1241);
  *(undefined1 *)(param_1 + 0x1241) = 1;
  iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x360))();
  if (iVar4 != 0) {
    FUN_00412825(param_1 + 0x360);
  }
  *(undefined1 *)(param_1 + 0x1241) = uVar1;
  FUN_004ff6fa(0x61616161,s_Scanning_Downloaded_Objects_006c36bc);
  iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x580))();
  if (iVar4 != 0) {
    FUN_00412825(param_1 + 0x580);
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 1) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_Livin__Large_Objects_006c369c);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x690))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,4);
      FUN_00412825(param_1 + 0x690);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 2) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_House_Party_Objects_006c367c);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x7a0))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,8);
      FUN_00412825(param_1 + 0x7a0);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 4) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_Hot_Date_Objects_006c3660);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x8b0))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,0x10);
      FUN_00412825(param_1 + 0x8b0);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 8) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_Vacation_Objects_006c3644);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x9c0))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,0x20);
      FUN_00412825(param_1 + 0x9c0);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x10) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_Deluxe_Objects_006c362c);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0xad0))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,0x40);
      FUN_00412825(param_1 + 0xad0);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_Unleashed_Objects_006c3610);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0xbe0))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,0x80);
      FUN_00412825(param_1 + 0xbe0);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_Superstar_Objects_006c35f4);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0xcf0))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,0x100);
      FUN_00412825(param_1 + 0xcf0);
    }
  }
  if (3 < *(short *)(DAT_006e486c + 0x66)) {
    FUN_004ff6fa(0x61616161,s_Scanning_Expansion_Shared_Object_006c35d0);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0xf10))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,0x200);
      FUN_00412825(param_1 + 0xf10);
    }
    FUN_004ff6fa(0x61616161,s_Scanning_NPC_Date_Objects_006c35b4);
    iVar4 = (*(code *)**(undefined4 **)(param_1 + 0x1020))();
    if (iVar4 != 0) {
      FUN_0043caa1(param_1,0x400);
      FUN_00412825(param_1 + 0x1020);
    }
  }
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x80) != 0) {
    FUN_004ff6fa(0x61616161,s_Scanning_Spellbound_Objects_006c3598);
    FUN_0043c3ec(param_1 + 0xe00,0x800);
  }
  if ((iVar2 - iVar3 >> 2 != *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2) &&
     (*(char *)(param_1 + 0x14) != '\0')) {
    FUN_0040766a(0xe0,0);
  }
  return;
}

