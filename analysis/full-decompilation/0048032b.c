
void FUN_0048032b(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 extraout_var;
  char *pcVar1;
  undefined1 local_104 [256];
  
  FUN_0046f824(local_104,0,0x100);
  FUN_0046fa24(0x28);
  if ((*(byte *)((int)param_1 + 5) & 4) == 0) {
    FUN_0048026d(*param_1,param_3);
  }
  else {
    FUN_0046f847(s_neighbor_in_stack_obj__006c57cc,0xffffffff);
  }
  FUN_0046f847(s___place_006c57c0,0xffffffff);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xa7,
               CONCAT22(extraout_var,(short)*(char *)(param_1 + 1)) + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  if ((*(char *)(param_1 + 1) == '\b') || (*(char *)(param_1 + 1) == '\t')) {
    FUN_0046fa24(0x20);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),0x19,(short)*(char *)((int)param_1 + 6),param_3,
                 param_4);
  }
  if (((uint)(int)*(char *)((int)param_1 + 5) >> 1 & 1) == 0) {
    if (((uint)(int)*(char *)((int)param_1 + 5) >> 4 & 1) == 0) goto LAB_00480421;
    pcVar1 = s___pass_temp_0_to_main_006c578c;
  }
  else {
    pcVar1 = s___pass_object_ids_to_main_006c57a4;
  }
  FUN_0046f847(pcVar1,0xffffffff);
LAB_00480421:
  if ((*(byte *)((int)param_1 + 5) & 1) != 0) {
    FUN_0046f847(s___do_not_duplicate_006c5778,0xffffffff);
  }
  if ((*(byte *)((int)param_1 + 5) & 8) != 0) {
    FUN_0046f847(s___fail_if_tile_is_non_empty_006c575c,0xffffffff);
  }
  if ((*(byte *)((int)param_1 + 5) & 0x40) != 0) {
    FUN_0046f847(s___ignore_walls_and_rooms_006c5740,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

