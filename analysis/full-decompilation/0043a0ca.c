
void FUN_0043a0ca(void)

{
  short sVar1;
  int iVar2;
  size_t sVar3;
  char *_Str;
  
  sVar1 = FUN_0047471f();
  iVar2 = (int)sVar1;
  if (1000 < iVar2) {
    if (iVar2 == 0x3e9) {
      _Str = s_Stack_underflow__006c2bb8;
    }
    else if (iVar2 == 0x44c) {
      _Str = s_Undefined_Transition__006c2bcc;
    }
    else if (iVar2 == 0x44d) {
      _Str = s_Too_many_iterations__006c2be4;
    }
    else if (iVar2 == 0x44e) {
      _Str = s_Transition_to_node_that_does_not_006c2bfc;
    }
    else {
      if (iVar2 != 0x44f) goto LAB_0043a390;
      _Str = s_Check_tree_primitive_blocked_com_006c2c24;
    }
    goto LAB_0043a381;
  }
  if (iVar2 == 1000) {
    _Str = s_Stack_overflow__006c2c50;
    goto LAB_0043a381;
  }
  switch(iVar2) {
  case 0:
    _Str = s_No_Error_006c3270;
    break;
  case 1:
    _Str = s_Bad_operator__006c3164;
    break;
  case 2:
    _Str = s_Temporary_reference_out_of_range_006c3140;
    break;
  case 3:
    _Str = s_Bad_parameter_to_update_primitiv_006c311c;
    break;
  case 4:
    _Str = s_Random_number_range_evaluated_to_006c30f4;
    break;
  case 5:
    _Str = s_Illegal_primitive_code__006c30dc;
    break;
  case 6:
    _Str = s_Attribute_number_out_of_range__006c30bc;
    break;
  case 7:
    _Str = s_Data_number_out_of_range__006c30a0;
    break;
  case 8:
    _Str = s_Stack_number_out_of_range__006c3084;
    break;
  case 9:
    _Str = s_Illegal_owner_field_in_data_refe_006c305c;
    break;
  case 10:
    _Str = s_Reference_to_tree_tree_parameter_006c3020;
    break;
  case 0xb:
    _Str = (char *)0x6c3018;
    break;
  case 0xc:
    _Str = s_Reference_to_target_object_when_n_006c2fe8;
    break;
  case 0xd:
    _Str = s_Flag_reference_is_out_of_range__006c2fc8;
    break;
  case 0xe:
    _Str = s_Undefined_transition_found__006c2fac;
    break;
  case 0xf:
    _Str = s_Reference_to_stack_object_out_of_006c2f84;
    break;
  case 0x10:
    _Str = s_Bad_alert_tree_number__006c2f6c;
    break;
  case 0x11:
    _Str = s_Bad_gosub_tree_number__006c2f54;
    break;
  case 0x12:
    _Str = s_Zero_distance_in_finding_directi_006c2f30;
    break;
  case 0x13:
    _Str = s_Expression_attempting_to_write_i_006c2efc;
    break;
  case 0x14:
    _Str = s_Data_value_out_of_range__006c2ee0;
    break;
  case 0x15:
    _Str = s_No_stack_object_present_when_req_006c2eb8;
    break;
  case 0x16:
    _Str = s_Reference_to_tree_table_entry_th_006c2e84;
    break;
  case 0x17:
    _Str = s_Could_not_find_object_reference__006c2e60;
    break;
  case 0x18:
    _Str = s_Standard_number_for_a_weight_ass_006c2e24;
    break;
  case 0x19:
    _Str = s_Weight_number_for_a_weight_assig_006c2dec;
    break;
  case 0x1a:
    _Str = s_Motive_number_out_of_range_or_no_006c2db4;
    break;
  case 0x1b:
    _Str = s_Slot_number_out_of_range__006c2d98;
    break;
  case 0x1c:
    _Str = s_Object_referred_to_must_be_a_per_006c2d70;
    break;
  case 0x1d:
    _Str = s_Balloon_Type_Is_Invalid__Values_a_006c2d2c;
    break;
  case 0x1e:
    _Str = s_Search_type_is_invalid__Types_ar_006c2cd4;
    break;
  case 0x1f:
    _Str = s_Tree_table_not_found_006c2cbc;
    break;
  case 0x20:
    _Str = s_Bad_target_slot_specified_in_rou_006c3244;
    break;
  case 0x21:
    _Str = s_Person_data_field_is_out_of_rang_006c3220;
    break;
  case 0x22:
    _Str = s_Show_hide_parameter_is_out_of_ex_006c31f0;
    break;
  case 0x23:
    _Str = s_Index_into_object_definition_out_006c327c;
    break;
  case 0x24:
    _Str = s_Invalid_snapping_mode_specified_006c31d0;
    break;
  case 0x25:
    _Str = s_Invalid_routing_slot_specified_006c31b0;
    break;
  case 0x26:
    _Str = s_Divide_by_zero__006c31a0;
    break;
  case 0x27:
    _Str = s_Bad_parameter_in_look_towards_pr_006c3174;
    break;
  case 0x28:
    _Str = s_Bad_room_id_specified_006c32a8;
    break;
  case 0x29:
    _Str = s_Bad_room_value_requested__006c32c0;
    break;
  case 0x2a:
    _Str = s_Invalid_global_sim_call__006c32dc;
    break;
  case 0x2b:
    _Str = s_Named_tree_does_not_exist__006c32f8;
    break;
  case 0x2c:
    _Str = s_Bad_parameter_to_call_named_tree_006c3314;
    break;
  case 0x2d:
    _Str = s_Unrecognized_priority_value__006c2c9c;
    break;
  case 0x2e:
    _Str = s_Invalid_constant__006c2c88;
    break;
  case 0x2f:
    _Str = s_Invalid_suit_location__006c334c;
    break;
  case 0x30:
    _Str = s_Invalid_suit_index__006c3338;
    break;
  case 0x31:
    _Str = s_Invliad_dynamic_sprite_index_006c3364;
    break;
  case 0x32:
    _Str = s_Invalid_object_id__006c2c74;
    break;
  case 0x33:
    _Str = s_Local_out_of_range__006c2c60;
    break;
  case 0x34:
    _Str = s_Object_for_routing_either_does_n_006c3384;
    break;
  case 0x35:
    _Str = s_Invalid_action_in_tutorial_primi_006c33c4;
    break;
  case 0x36:
    _Str = s_More_than_one_passing_value_spec_006c33ec;
    break;
  default:
    goto LAB_0043a390;
  case 0x38:
    _Str = s_Bad_expense_type_specified__006c3414;
    break;
  case 0x39:
    _Str = s_Career_id_not_found__006c3444;
    break;
  case 0x3a:
    _Str = s_Job_data_not_found__006c3430;
    break;
  case 0x3b:
    _Str = s_Invalid_skin_color__006c345c;
    break;
  case 0x3c:
    _Str = s_Neighborhood_data_index_out_of_r_006c3470;
    break;
  case 0x3d:
    _Str = s_Start_object_required__006c3498;
    break;
  case 0x3e:
    _Str = s_Tree_break_encountered__006c34b0;
  }
LAB_0043a381:
  if ((_Str == (char *)0x0) || (sVar3 = _strlen(_Str), sVar3 == 0)) {
LAB_0043a390:
    _Str = s_Condition_unknown__006c2ba4;
  }
  FUN_0046f8cb(_Str);
  return;
}

